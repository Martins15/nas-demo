require 'yaml'

dir = File.dirname(File.expand_path(__FILE__))

configValues = YAML.load_file("#{dir}/puphpet/config.yaml")
data = configValues['vagrantfile-local']

if !data['vm']['provider']['virtualbox'].empty?
  ENV['VAGRANT_DEFAULT_PROVIDER'] = 'virtualbox'
end

Vagrant.configure("2") do |config|
  config.vm.box = "#{data['vm']['box']}"
  config.vm.box_url = "#{data['vm']['box_url']}"

  if data['vm']['hostname'].to_s != ''
    config.vm.hostname = "#{data['vm']['hostname']}"
  end

  if data['vm']['network']['private_network'].to_s != ''
    config.vm.network "private_network", ip: "#{data['vm']['network']['private_network']}"
  end

  data['vm']['network']['forwarded_port'].each do |i, port|
    if port['guest'] != '' && port['host'] != ''
      config.vm.network :forwarded_port, guest: port['guest'].to_i, host: port['host'].to_i
    end
  end

  data['vm']['synced_folder'].each do |i, folder|
    if folder['source'] != '' && folder['target'] != '' && folder['id'] != ''
      nfs = (folder['nfs'] == "true") ? "nfs" : nil
      config.vm.synced_folder "#{folder['source']}", "#{folder['target']}", id: "#{folder['id']}", type: nfs
    end
  end

  config.vm.usable_port_range = (10200..10500)

  if !data['vm']['provider']['virtualbox'].empty?
    config.vm.provider :virtualbox do |virtualbox|
      data['vm']['provider']['virtualbox']['modifyvm'].each do |key, value|
        if key == "natdnshostresolver1"
          value = value ? "on" : "off"
        end
        virtualbox.customize ["modifyvm", :id, "--#{key}", "#{value}"]
      end
    end
  end

  config.vm.provision "shell" do |s|
    s.path = "puphpet/shell/initial-setup.sh"
    s.args = "/vagrant/puphpet"
  end

  # Install ansible inside the box.
  config.vm.provision :shell, :path => "puphpet/shell/ansible.sh"

  # Install ansible playbooks inside the box.
  config.vm.provision :shell, :path => "puphpet/ansible/run-ansible-playbook.sh"

end


