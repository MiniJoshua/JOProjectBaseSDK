
Pod::Spec.new do |s|

  s.name         = "JOProjectBaseSDK"
  s.version      = "1.1.24"
  s.summary      = "Project Base SDK"
  s.homepage     = "https://github.com/xinlidexiaoman/JOProjectBaseSDK"
  s.license      = "MIT"
  s.author        = { "Joshua" => "505398605@qq.com" }
  s.platform     = :ios, '7.0'
  s.source       = { :git => "https://github.com/xinlidexiaoman/JOProjectBaseSDK.git", :tag => s.version}
  s.source_files  = 'JOBaseSDK/**/JOProjectBaseSDK.h'

  s.resource = 'JOBaseSDK/Resources/**/*.{png,txt,a}'
  #s.resources = ['JOBaseSDK/Resources/**/*.{png}']

  #s.framework  = "sqlite3"
  s.frameworks = "SystemConfiguration", "Security", "MobileCoreServices", "CoreGraphics"

  s.library   = "sqlite3"
  #s.libraries = "sqlite3", "libJOProjectBaseSDK"
  s.vendored_libraries = "JOBaseSDK/Resources/libJOProjectBaseSDK.a"

  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = true

s.subspec 'Function' do |ss|

s.subspec 'Functionss' do |sss|
ss.source_files = 'JOBaseSDK/**/JO{DataRequestConfig,FileDownloadConfig,FileUploadConfig,HttpRequestType,FAppInfo,FAutoLayout,FCrash,FDataBase,FDataBaseProperty,FDataBaseSQL,FDeviceInfo,FException,FFileManage,FLog,FunctionDefine,FunctionObject,NetRequestManage,Layout,LayoutItem,RequestConfig}.h'
end

end

s.subspec 'JSONModel' do |ss|
ss.source_files = 'JOBaseSDK/**/JSON{Model,KeyMapper,ModelArray,ModelError,ValueTransformer}.h'
end

s.subspec 'Extend' do |ss|
ss.source_files = 'JOBaseSDK/**/{UIColor+JOExtend,NSString+JOExtend,NSObject+JOExtend,UIView+JOExtend,UIImage+JOExtend,UIFont+JOExtend,UILabel+JOExtend,NSArray+JOExtend}.h'
end

s.subspec 'Macro' do |ss|
ss.source_files = 'JOBaseSDK/**/JO{Macro}.h'
end

  s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libJOProjectBaseSDK" }

end
