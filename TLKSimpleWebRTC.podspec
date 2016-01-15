Pod::Spec.new do |s|
  s.name         = "TLKSimpleWebRTC"
  s.version      = "1.0.1"
  s.summary      = "A iOS interface to a SimpleWebRTC based signalling server using Socket.io"
  s.homepage     = "https://github.com/otalk/TLKSimpleWebRTC"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "Jon Hjelle" => "hjon@andyet.com",
                     "&yet" => "contact@andyet.com" }
  s.platform     = :ios, '7.0'
  s.source       = { :git => "https://github.com/otalk/TLKSimpleWebRTC.git", :tag => s.version.to_s }
  s.source_files = "Classes/*.{h,m}"
  s.requires_arc = true
  s.dependency 'AZSocketIO', '0.0.6'
end
