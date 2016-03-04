# JOProjectBaseSDK
It's a base sdk for project. Let's do it.
Create by Joshua

1.1.12版本:
更新内容:网络请求模块,现在可以在方法内直接生成临时变量做一个网络请求,而不需要把网络请求的manage设置成对象的成员变量.
//TODO:下面一个小更新会把所有的网络请求返回状态的回调合并到一个方法里面,更方便达到一个网络请求的效果。(已完成)

1.1.15:网络循环引用问题测试解决方案

1.1.16:本次把所有的网络请求返回状态的回调合并到一个方法里面,更方便达到一个网络请求的效果。
现在可以如下操作:

    JOHttpsRequestDataConfig *httpRequestDataConfig = [JOHttpsRequestDataConfig new];
    [httpRequestDataConfig setHttpURLString:@"你的URL地址" postData:@"需要的参数(字典类型)" requestType:HttpRequestTypePost];
    [JONetRequestManage startNetRequestManageWithConfig:httpRequestDataConfig progressHandler:^(CGFloat progressValue) {
        //文件的上传与下载的进度值.
    } jsonModelHandler:^(JSONModelParseHandler parseHandler) {
        //得到具体转换后的数据模型
    } successHandler:^(id completeObject, NSInteger completeTag) {
    JOLog(@"得到返回的数据:%@",completeObject);//服务器返回的具体的数据.
    } interruptHandler:^(id interruptObject, NSInteger interruptTag) {
    JOLog(@"失败的原因:%@",interruptObject);//网络失败的返回的原因
    }];

