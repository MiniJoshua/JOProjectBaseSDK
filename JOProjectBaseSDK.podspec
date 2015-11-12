
Pod::Spec.new do |s|

  s.name         = "JOProjectBaseSDK"
  s.version      = "1.0.6"
  s.summary      = "Project Base SDK"
  s.homepage     = "https://github.com/xinlidexiaoman/JOProjectBaseSDK"
  s.license      = "MIT"
  s.author        = { "Joshua" => "505398605@qq.com" }
  s.platform     = :ios, '7.0'
  s.source       = { :git => "https://github.com/xinlidexiaoman/JOProjectBaseSDK.git", :tag => s.version}
  s.source_files  = 'JOBaseSDK/**/*.{h,m}'

  s.resource = 'JOBaseSDK/Resources/**/*.{png,txt,a}'
  #s.resources = ['JOBaseSDK/Resources/**/*.{png}']

  # s.framework  = "SomeFramework"
  # s.frameworks = "SomeFramework", "AnotherFramework"

  # s.library   = "iconv"
  # s.libraries = "iconv", "xml2"

  s.requires_arc = true

  s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libsqlite3.0" }

end
