<?php
/**
 * @file
 * Press contact block.
 *
 * Available variables:
 * - $name: name of the person.
 * - $title: person's title.
 * - $address: office address.
 * - $phone: phone number.
 */
?>
<section class="medium-12 clearfix article-sidebar-section contact-info">
  <h5><?php print $title; ?></h5>
  <?php foreach ($contacts as $contact): ?>
    <p><strong><?php print $contact['name']; ?></strong><br>
      <?php if (!empty($contact['position'])): ?>
        <?php print $contact['position']; ?><br/>
      <?php endif;?>
      <?php if (!empty($contact['office'])): ?>
        <?php print $contact['office']; ?>
      <?php endif;?>
    </p>
      <?php if (!empty($contact['address'])): ?>
        <p><?php print $contact['address']; ?></p>
      <?php endif;?>
      <?php if (!empty($contact['email'])): ?>
        <p><a href="mailto:<?php print $contact['email']; ?>"><?php print $contact['email']; ?></a></p>
      <?php endif;?>
      <?php if (!empty($contact['phone'])): ?>
        <p><?php print $contact['phone']; ?></p>
      <?php endif;?>
  <?php  endforeach; ?>
</section>
