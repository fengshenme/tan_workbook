/*
C++ Web 编程
什么是 CGI？
公共网关接口（CGI），是一套标准，定义了信息是如何在 Web 服务器和客户端脚本之间进行交换的。
CGI 规范目前是由 NCSA 维护的，NCSA 定义 CGI 如下：
公共网关接口（CGI），是一种用于外部网关程序与信息服务器（如 HTTP 服务器）对接的接口标准。
目前的版本是 CGI/1.1，CGI/1.2 版本正在推进中。
Web 浏览
为了更好地了解 CGI 的概念，让我们点击一个超链接，浏览一个特定的网页或 URL，看看会发生什么。

您的浏览器联系上 HTTP Web 服务器，并请求 URL，即文件名。
Web 服务器将解析 URL，并查找文件名。如果找到请求的文件，Web 服务器会把文件发送回浏览器，否则发送一条错误消息，表明您请求了一个错误的文件。
Web 浏览器从 Web 服务器获取响应，并根据接收到的响应来显示文件或错误消息。
然而，以这种方式搭建起来的 HTTP 服务器，不管何时请求目录中的某个文件，HTTP 服务器发送回来的不是该文件，而是以程序形式执行，并把执行产生的输出发送回浏览器显示出来。

公共网关接口（CGI），是使得应用程序（称为 CGI 程序或 CGI 脚本）能够与 Web 服务器以及客户端进行交互的标准协议。这些 CGI 程序可以用 Python、PERL、Shell、C 或 C++ 等进行编写。

CGI 架构图
下图演示了 CGI 的架构：

CGI 架构
Web 服务器配置
在您进行 CGI 编程之前，请确保您的 Web 服务器支持 CGI，并已配置成可以处理 CGI 程序。所有由 HTTP 服务器执行的 CGI 程序，都必须在预配置的目录中。该目录称为 CGI 目录，按照惯例命名为 /var/www/cgi-bin。虽然 CGI 文件是 C++ 可执行文件，但是按照惯例它的扩展名是 .cgi。

默认情况下，Apache Web 服务器会配置在 /var/www/cgi-bin 中运行 CGI 程序。如果您想指定其他目录来运行 CGI 脚本，您可以在 httpd.conf 文件中修改以下部分：
*/

#include <iostream>
using namespace std;
 
int main ()
{
    
   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>Hello World - 第一个 CGI 程序</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "<h2>Hello World! 这是我的第一个 CGI 程序</h2>\n";
   cout << "</body>\n";
   cout << "</html>\n";
   
   return 0;
}
/*
编译上面的代码，把可执行文件命名为 cplusplus.cgi，并把这个文件保存在 /var/www/cgi-bin 目录中。在运行 CGI 程序之前，请使用 chmod 755 cplusplus.cgi UNIX 命令来修改文件模式，确保文件可执行。访问可执行文件，您会看到下面的输出：

Hello World! 这是我的第一个 CGI 程序
上面的 C++ 程序是一个简单的程序，把它的输出写在 STDOUT 文件上，即显示在屏幕上。在这里，值得注意一点，第一行输出 Content-type:text/html\r\n\r\n。这一行发送回浏览器，并指定要显示在浏览器窗口上的内容类型。您必须理解 CGI 的基本概念，这样才能进一步使用 Python 编写更多复杂的 CGI 程序。C++ CGI 程序可以与任何其他外部的系统（如 RDBMS）进行交互。

HTTP 头信息
行 Content-type:text/html\r\n\r\n 是 HTTP 头信息的组成部分，它被发送到浏览器，以便更好地理解页面内容。HTTP 头信息的形式如下：

HTTP 字段名称: 字段内容
 
例如
Content-type: text/html\r\n\r\n
还有一些其他的重要的 HTTP 头信息，这些在您的 CGI 编程中都会经常被用到。

头信息	描述
Content-type:	MIME 字符串，定义返回的文件格式。例如 Content-type:text/html。
Expires: Date	信息变成无效的日期。浏览器使用它来判断一个页面何时需要刷新。一个有效的日期字符串的格式应为 01 Jan 1998 12:00:00 GMT。
Location: URL	这个 URL 是指应该返回的 URL，而不是请求的 URL。你可以使用它来重定向一个请求到任意的文件。
Last-modified: Date	资源的最后修改日期。
Content-length: N	要返回的数据的长度，以字节为单位。浏览器使用这个值来表示一个文件的预计下载时间。
Set-Cookie: String	通过 string 设置 cookie。
CGI 环境变量
所有的 CGI 程序都可以访问下列的环境变量。这些变量在编写 CGI 程序时扮演了非常重要的角色。

变量名	描述
CONTENT_TYPE	内容的数据类型。当客户端向服务器发送附加内容时使用。例如，文件上传等功能。
CONTENT_LENGTH	查询的信息长度。只对 POST 请求可用。
HTTP_COOKIE	以键 & 值对的形式返回设置的 cookies。
HTTP_USER_AGENT	用户代理请求标头字段，递交用户发起请求的有关信息，包含了浏览器的名称、版本和其他平台性的附加信息。
PATH_INFO	CGI 脚本的路径。
QUERY_STRING	通过 GET 方法发送请求时的 URL 编码信息，包含 URL 中问号后面的参数。
REMOTE_ADDR	发出请求的远程主机的 IP 地址。这在日志记录和认证时是非常有用的。
REMOTE_HOST	发出请求的主机的完全限定名称。如果此信息不可用，则可以用 REMOTE_ADDR 来获取 IP 地址。
REQUEST_METHOD	用于发出请求的方法。最常见的方法是 GET 和 POST。
SCRIPT_FILENAME	CGI 脚本的完整路径。
SCRIPT_NAME	CGI 脚本的名称。
SERVER_NAME	服务器的主机名或 IP 地址。
SERVER_SOFTWARE	服务器上运行的软件的名称和版本。
下面的 CGI 程序列出了所有的 CGI 变量。

*/


