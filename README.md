# JOProjectBaseSDK
It's a base sdk for project. Let's do it.
Create by Joshua

使用:pod 'JOProjectBaseSDK' 即可

1.1.19:本次修复了一个BUG:取消一个下载任务的时候,等想恢复的时候想删除原来的缓存好的数据,却只删除了缓存信息,而未真正删除缓存文件的的错误.

    增加了对一个下载任务,如果资源的URL是有时效的,每一次请求资源的URL都会发生改变的处理。
    
    整理了通过pod命令部署到项目中文件分类的问题,现在可以不同的头文件能在其对应的功能文件夹中,方便查看.

1.1.18:本次改动针对网络请求这一块:增加了一个identifier的参数来标示一个网络请求,在这个网络未完成之前你随时都能取消这个网络请求.文件下载的网络请求,取消的时候会自动缓存已经下好的数据,你下次继续上次下载完的地方继续下载.

现在要开始一个网络请求只需要自定义你的网络config类的属性即可.

一个完整图片下载与取消的网络示例:

    JOFileDownloadConfig *fileDownloadConfig = [JOFileDownloadConfig new];
    [fileDownloadConfig setFileSavePath:[JOFFileManage documentPath] fileSaveName:@"download.jpg" isCleanExistFile:NO];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://p1.pichost.me/i/40/1639665.png"]];
    fileDownloadConfig.request = request;
    
//开始

    [JONetRequestManage startNetRequestManageWithConfig:fileDownloadConfig requestIdentifier:@"ImageDownload" fileProgressHandler:^(CGFloat progressValue) {
        JOLog(@"progressValue:%f",progressValue);
    } jsonModelHandler:^(JSONModelParseHandler parseHandler) {
    } successHandler:^(NSDictionary *response) {
        JOLog(@"下载完成:%@",response);
    } failedHandler:^(NSString *failedDescription) {
        JOLog(@"失败的原因:%@",failedDescription);
    }];

//取消

    [JONetRequestManage cancelNetRequestWithIdentifier:@"ImageDownload"];

1.1.17:本次把所有的网络请求返回状态的回调合并到一个方法里面,更方便达到一个网络请求的效果。

1.1.15:网络循环引用问题测试解决方案

1.1.12版本:
更新内容:网络请求模块,现在可以在方法内直接生成临时变量做一个网络请求,而不需要把网络请求的manage设置成对象的成员变量.
//TODO:下面一个小更新会把所有的网络请求返回状态的回调合并到一个方法里面,更方便达到一个网络请求的效果。(已完成)







