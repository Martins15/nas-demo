/**
 * @file
 * Javascript for the interface at netx tree tab.
 */

(function ($) {
    /**
     * Functionality for the administrative file listings.
     */
    Drupal.behaviors.netxCfb = {
        attach: function (context) {
            $('body').once('netxCfb', function(){
                var filemanager = $('.cfbfilemanager'),
                    breadcrumbs = $('.cfbbreadcrumbs'),
                    pager = $('.cfbpager'),
                    fileList = filemanager.find('.cfbdata');

                // Start by fetching the file data from menu callback with an AJAX request.
                // @todo refactor for do not start with getting tree.
                $.get(Drupal.settings.basePath + 'netx-scan-tree', function (data) {

                var response = [data],
                    currentPath = '',
                    breadcrumbsUrls = [];

                var folders = [],
                    files = [];

                // This event listener monitors changes on the URL. We use it to
                // capture back/forward navigation in the browser.
                $(window).bind('hashchange', function () {
                    var hash = decodeURIComponent(window.location.hash).split('?pager=');
                    if (hash.length > 1) {
                        goto(encodeURIComponent(hash[0]), {
                            page: parseInt(hash[1])
                        });
                    }
                    else {
                        goto(encodeURIComponent(hash[0]));
                    }
                    // We are triggering the event. This will execute
                    // this function on page load, so that we show the correct folder:
                }).trigger('hashchange');

                // Hiding and showing the search box.
                filemanager.find('.search').click(function () {
                    var search = $(this);
                    search.find('span').hide();
                    search.find('input[type=search]').show().focus();
                });

                // Listening for keyboard input on the search field.
                // We are using the "input" event which detects cut and paste
                // in addition to keyboard input.
                filemanager.find('input').bind('input', function (e) {
                    folders = [];
                    files = [];
                    var value = this.value.trim();

                    if (value.length) {
                        filemanager.addClass('searching');

                        // Update the hash on every key stroke
                        window.location.hash = 'search=' + value.trim();
                    }
                    else {
                        filemanager.removeClass('searching');
                        window.location.hash = encodeURIComponent(currentPath);
                    }

                }).bind('keyup', function (e) {

                    // Clicking 'ESC' button triggers focus out and cancels the search.
                    var search = $(this);
                    if (e.keyCode == 27) {
                        search.trigger('focusout');
                    }
                }).focusout(function (e) {
                    // Cancel the search.
                    var search = $(this);
                    if (!search.val().trim().length) {
                        window.location.hash = encodeURIComponent(currentPath);
                        search.hide();
                        search.parent().find('span').show();
                    }
                });

                // Clicking on folders.
                $('li.cfb__folder').live('click', function(e) {
                    e.preventDefault();
                    var nextDir = $('.folders', this).attr('href');
                    var msg = Drupal.t('Please wait. Getting list. This can take a while.', [], []);
                    $(this).html('<span class="label-wrapper">' + msg + '</span>');

                    if (filemanager.hasClass('searching')) {
                        // Building the breadcrumbs.
                        breadcrumbsUrls = generateBreadcrumbs(nextDir);
                        filemanager.removeClass('searching');
                        filemanager.find('input[type=search]').val('').hide();
                        filemanager.find('span').show();
                    }
                    else {
                        breadcrumbsUrls.push(nextDir);
                    }
                    window.location.hash = encodeURIComponent(nextDir);
                    currentPath = nextDir;
                });

                // Clicking on breadcrumbs.
                $('.cfbbreadcrumbs a').live('click', function(e) {
                    e.preventDefault();
                    var index = breadcrumbs.find('a').index($(this)),
                        nextDir = breadcrumbsUrls[index];
                    breadcrumbsUrls.length = Number(index);
                    window.location.hash = encodeURIComponent(nextDir);
                });

                // Clicking on pager links.
                $('.cfbpager a').live('click', function(e) {
                    e.preventDefault();
                    var page = $(this).data('page');
                    var url = $(this).attr('href') + '?pager=' + page;
                    window.location.hash = encodeURIComponent(url);
                });

                // Navigates to the given hash (path)
                function goto(hash, options) {
                    options = $.extend({page: 0}, options);
                    hash = decodeURIComponent(hash).slice(1).split('=');

                    if (hash.length) {
                        var rendered = '';
                        // If hash has search in it.
                        if (hash[0] === 'search') {
                            filemanager.addClass('searching');
                            rendered = searchData(response, hash[1].toLowerCase());
                            if (rendered.length) {
                                currentPath = hash[0];
                            }
                            render(rendered);
                        }

                        // If hash is some path.
                        else if (hash[0].trim().length) {
                            rendered = searchByPath(hash[0], options);
                            if (rendered.length) {
                                currentPath = hash[0];
                                breadcrumbsUrls = generateBreadcrumbs(hash[0]);
                                render(rendered);
                            }
                            else {
                                currentPath = hash[0];
                                breadcrumbsUrls = generateBreadcrumbs(hash[0]);
                                render(rendered);
                            }
                        }

                        // If there is no hash.
                        else {
                            currentPath = data.path;
                            breadcrumbsUrls.push(data.path);
                            render(searchByPath(data.path, options));
                        }
                    }
                }

                // Splits a file path and turns it into clickable breadcrumbs
                function generateBreadcrumbs(nextDir) {
                    var path = nextDir.split('/').slice(0);
                    for (var i = 1; i < path.length; i++) {
                        path[i] = path[i - 1] + '/' + path[i];
                    }
                    return path;
                }

                // Locates a file by path.
                function searchByPath(dir, options) {
                    options = $.extend({page: 0}, options);
                    var path = dir.split('/'),
                        demo = null,
                        flag = 0;
                    var scriptUrl = Drupal.settings.basePath + 'netx-scan-tree' + '/' + dir;
                    if (options.page !== 0) {
                        scriptUrl += '?pager=' + options.page;
                    }
                    $.ajax({
                        url: scriptUrl,
                        type: 'get',
                        dataType: 'json',
                        async: false,
                        success: function (data) {
                            demo = [data];
                        }
                    });
                    for (var i = 0; i < path.length; i++) {
                        for (var j = 0; j < demo.length; j++) {
                            if (demo[j].name === path[i]) {
                                flag = 1;
                                demo = demo[j].items;
                                break;
                            }
                        }
                    }
                    demo = flag ? demo : [];
                    return demo;
                }

                // Recursively search through the file tree.
                function searchData(data, searchTerms) {

                    data.forEach(function (d) {
                        if (d.type === 'folder') {
                            searchData(d.items, searchTerms);

                            if (d.name.toLowerCase().match(searchTerms)) {
                                folders.push(d);
                            }
                        }
                        else if (d.type === 'file') {
                            if (d.name.toLowerCase().match(searchTerms)) {
                                files.push(d);
                            }
                        }
                    });
                    return {folders: folders, files: files};
                }

                // Render the HTML for the file manager.
                function render(data) {
                    var scannedFolders = [],
                        scannedFiles = [],
                        scannedPagers = [];
                    if (Array.isArray(data)) {
                        data.forEach(function (d) {
                            if (d.type === 'folder') {
                                scannedFolders.push(d);
                            }
                            else if (d.type === 'file') {
                                scannedFiles.push(d);
                            }
                            else if (d.type === 'pager') {
                                scannedPagers.push(d);
                            }
                        });
                    }
                    else if (typeof data === 'object') {
                        data = $.extend({
                            folders: [],
                            files: [],
                            pagers: []
                        }, data);
                        scannedFolders = data.folders;
                        scannedFiles = data.files;
                        scannedPagers = data.pagers;
                    }

                    // Empty the old result and make the new one.
                    fileList.empty().hide();
                    if (!scannedFolders.length && !scannedFiles.length) {
                        filemanager.find('.nothingfound').show();
                    }
                    else {
                        filemanager.find('.nothingfound').hide();
                    }
                    if (scannedFolders.length) {
                        scannedFolders.forEach(function (f) {
                            var itemsLength = f.items.length,
                                name = escapeHTML(f.name),
                                icon = '<span class="icon folder"></span>';
                            if (itemsLength) {
                                icon = '<span class="icon folder full"></span>';
                            }
                            if (itemsLength == 1) {
                                itemsLength += ' subcategory';
                            }
                            else if (itemsLength > 1) {
                                itemsLength += ' subcategories';
                            }
                            else {
                                itemsLength = 'Click to get items';
                            }
                            var folder = $('<li class="cfb__folder media-item"><a href="' + f.path + '" title="' + f.path + '" class="folders">' + icon + '<div class="label-wrapper"><span class="name">' + name + '</span> <span class="details">' + itemsLength + '</span></div></a></li>');
                            folder.appendTo(fileList);
                        });
                    }

                    // Preview for images in table.
                    if (scannedFiles.length) {
                        fileList.wrap("<div class='audubon-netx-preview'></div>");
                        var tHead = $('<table><thead><tr><th>Image</th><th>Filename</th><th>Dimensions</th></tr></thead><tbody>');
                        var tbodyEnd = $('</tbody>');
                        tHead.appendTo(fileList);
                        scannedFiles.forEach(function (f) {
                            var fileSize = bytesToSize(f.size),
                                name = escapeHTML(f.name),
                                assetId = parseInt(f.assetId),
                                fileType = name.split('.'),
                                preview = f.assetPreview,
                                icon = '<span class="icon file"></span>';
                            dimensions = escapeHTML(f.dimensions) + 'px';
                            fileType = fileType[fileType.length - 1];
                            // @todo change icons with a real image thumbnails.
                            icon = '<span class="icon file f-' + fileType + '">.' + fileType + '</span>';
                            // @todo add class for ability to have selections for a form.

                            var rowStart = '<tr class="sfb__file" assetId="' + assetId + '">',
                                image = '<td>' + preview + '</td>',
                                fileName = '<td>' + name + '</td>',
                                dimensions = '<td>' + dimensions + '</td>',
                                rowEnd = '</tr>',
                                file = $(rowStart + image + fileName + dimensions + rowEnd);
                            file.find('.label-wrapper').remove();
                            file.appendTo(fileList);
                        });
                        tbodyEnd.appendTo(fileList);
                    }

                    pager.empty();
                    if (scannedPagers.length) {
                        scannedPagers.forEach(function (f) {
                            // If pages more one add pagination.
                            if (f.pages > 1) {
                                var $pagerList = $('<ul class="netx-pager"></ul>'),
                                    $pagerMiddle = 5,
                                    // Current is the page we are currently paged to.
                                    $pagerCurrent = parseInt(f.current),
                                    // First is the first page listed by this pager piece (re quantity).
                                    $pagerFirst = $pagerCurrent - $pagerMiddle,
                                    // Last is the last page listed by this pager piece (re quantity).
                                    $pagerLast = $pagerCurrent + $pagerMiddle,
                                    // Max is the maximum page number.
                                    $pagerMax = f.pages - 1,
                                    $pagerItem = '';

                                // Prepare item offset for generation loop.
                                var $item = $pagerFirst;
                                // Adjust "center" if at end of query.
                                if ($pagerLast > $pagerMax) {
                                    $item = $item + ($pagerMax - $pagerLast);
                                    $pagerLast = $pagerMax;
                                }
                                // Adjust "center" if at start of query.
                                if ($item <= 0) {
                                    $item = 1;
                                }
                                // Add Previous page link or text.
                                if ($pagerCurrent != 0) {
                                    $pagerItem = $('<li class="netx-pager-item">' +
                                        '<a href="' + currentPath + '" data-page="' + ($pagerCurrent - 1) + '">' + Drupal.t('Previous page') + '</a>' + '</li>');
                                    $pagerItem.appendTo($pagerList);
                                }
                                else {
                                    $pagerItem = $('<li class="netx-pager-item">' +
                                        '<span>' + Drupal.t('Previous page') + '</span>' + '</li>');
                                    $pagerItem.appendTo($pagerList);
                                }
                                // Add first item.
                                $pagerItem = $('<li class="netx-pager-item">' +
                                    '<a href="' + currentPath + '" data-page="0">1</a>' + '</li>');
                                $pagerItem.appendTo($pagerList);

                                if ($item > 1) {
                                    $pagerItem = $('<li class="netx-pager-item">' +
                                        '<span>...</span>' + '</li>');
                                    $pagerItem.appendTo($pagerList);
                                }
                                // Generate page list.
                                for (var i = $item; i < $pagerLast; i++) {
                                    $pagerItem = $('<li class="netx-pager-item">' +
                                        '<a href="' + currentPath + '" data-page="' + i + '">' + (i + 1) + '</a>' +
                                        '</li>');
                                    if (i == $pagerCurrent) {
                                        // Add specific class for current item.
                                        $pagerItem.addClass('current');
                                    }
                                    $pagerItem.appendTo($pagerList);
                                }

                                if (i < $pagerMax) {
                                    $pagerItem = $('<li class="netx-pager-item">' +
                                        '<span>...</span>' + '</li>');
                                    $pagerItem.appendTo($pagerList);
                                }
                                // Add last item.
                                $pagerItem = $('<li class="netx-pager-item">' +
                                    '<a href="' + currentPath + '" data-page="' + $pagerMax + '">' + ($pagerMax + 1) + '</a>' + '</li>');
                                $pagerItem.appendTo($pagerList);
                                // Add Next page link or text.
                                if ($pagerCurrent != $pagerMax) {
                                    $pagerItem = $('<li class="netx-pager-item">' +
                                        '<a href="' + currentPath + '" data-page="' + ($pagerCurrent + 1) + '">' + Drupal.t('Next page') + '</a>' + '</li>');
                                    $pagerItem.appendTo($pagerList);
                                }
                                else {
                                    $pagerItem = $('<li class="netx-pager-item">' +
                                        '<span>' + Drupal.t('Next page') + '</span>' + '</li>');
                                    $pagerItem.appendTo($pagerList);
                                }
                                $pagerList.appendTo(pager);
                            }
                        });
                    }


                    // Generate the breadcrumbs.
                    var url = '';
                    if (filemanager.hasClass('searching')) {
                        url = '<span>Search results: </span>';
                    }
                    else {
                        breadcrumbsUrls.forEach(function (u, i) {
                            var name = u.split('/');
                            if (i !== breadcrumbsUrls.length - 1) {
                                url += '<a href="' + u + '"><span class="folderName">' + name[name.length - 1] + '</span></a> <span class="arrow">→</span> ';
                            }
                            else {
                                url += '<span class="folderName">' + name[name.length - 1] + '</span>';
                            }
                        });
                    }
                    breadcrumbs.text('').append(url);

                    // Show the generated elements.
                    fileList.addClass('media-list-thumbnails');
                    fileList.show();

                    // Mark file item as selected.
                    $('.sfb__file', fileList).once('netx', function() {
                        var that = this;
                        $('.media-item', this).click(function() {
                            $('.media-item', fileList).removeClass('selected');
                            $(this).addClass('selected');
                            // Assign assetId to hidden form element.
                            $('#cfbfile-id input').val($(that).attr('assetId'));
                        });
                    });
                }

                // This function escapes special html characters in names.
                function escapeHTML(text) {
                    // @todo debug why there is a null category.
                    if (text === null) {
                        return text;
                    }
                    return text.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
                }

                // Convert file sizes from bytes to human readable units.
                function bytesToSize(bytes) {
                    var sizes = ['Bytes', 'KB', 'MB', 'GB', 'TB'];
                    if (bytes === 0) return '0 Bytes';
                    var i = parseInt(Math.floor(Math.log(bytes) / Math.log(1024)));
                    return Math.round(bytes / Math.pow(1024, i), 2) + ' ' + sizes[i];
                }
            });
            });
        }
    };

})(jQuery);
