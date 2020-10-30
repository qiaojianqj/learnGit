###JAVA WEB 基础###

**AJAX跨域访问**方式之一CORS（Cross-origin resource sharing）：

http://www.ruanyifeng.com/blog/2016/04/cors.html

https://segmentfault.com/a/1190000012469713

AJAX跨域访问方式之二JSONP：

https://www.cnblogs.com/chopper/archive/2012/03/24/2403945.html

**HTTP协议** :(http头添加跨域信息Origin)

OPTIONS:

![image-20180728175135803](/Users/qiaojian/Documents/learnGit/markdown/http-options.png)

POST:

![image-20180728175247506](/Users/qiaojian/Documents/learnGit/markdown/http-post.png)

GET:

![image-20180728175334315](/Users/qiaojian/Documents/learnGit/markdown/http-get.png)

Response-200:

![image-20180728175446821](/Users/qiaojian/Documents/learnGit/markdown/http-status-200.png)

Response-500:

![image-20180728175625328](/Users/qiaojian/Documents/learnGit/markdown/http-status-500.png)

**HTML**

**JavaScript** - 基于对象，操作DOM对象，事件处理

**XML** - 解析接口DOM、SAX; 解析框架JDOM、DOM4J

~~~
[qiaojian@Mac 代码 ]% javac -classpath ./jdom.jar -d . -encoding gbk  *.java                      [1]
[qiaojian@Mac 代码 ]% java -classpath ./jdom.jar:. org.lxh.xml.jdom.ReadXML
~~~

**Tomcat**

~~~
Tomcat目录结构：
bin：存放的是可执行文件(startup.sh & shutdown.sh)
conf：存放的是Tomcat服务器的各种全局配置文件，其中包括server.xml（Tomcat的主要配置文件）、tomcat-users.xml和web.xml等配置文件。
lib：存放tomcat服务器所需的各种jar文件。
logs：存放Tomcat的日志文件目录，记录了Tomcat启动和关闭的信息，以及异常信息等。
temp：存放Tomcat的临时文件，这个目录下的东西可以停止后删除。
webapps：存放web项目的目录，其中每个文件夹都是一个项目。
work：运行时生成的文件，最终运行的文件都在这里。通过webapps中的项目生成的。删除后再次运行会重新生成。
~~~

~~~
按照 Java EE 规范的规定，一个典型的Web应用程序有四个部分： 
1. 公开目录 
2. WEB-INF/web.xml 文件，发布描述符（必选） 
3. WEB-INF/classes 目录，编译后的Java 类文件（可选） 
4. WEB-INF/lib 目录，Java 类库文件（*.jar）（可选）
~~~

客户端第一次发起请求时，服务器端创建session并生成JSESSIONID，然后通过response返回给浏览器；

之后浏览器再次发起请求时，会带上浏览器上缓存的cookie-JSESSIONID，服务器端会判断JSESSIONID是否正确，然后进行SESSION相关的操作。JSESSIONID存在浏览器的cookie里，不同的浏览器JSESSIONID不一样。

**JSP**

~~~
Tomcat 会将jsp文件翻译成对应的java文件并编译成class文件放在work目录下。JSP即是一个Servlet程序的封装。
~~~

指令用于设置jsp页面相关属性：

~~~jsp
<%@ page language="java" contentType="text/html" pageEncoding="GBK"%>
~~~

静态包含文件：不可以传递参数，简单替换，有可能出现变量重复定义错误

~~~jsp
<%@include file="include.jsp"%>
~~~

动态包含文件：可以传递参数，会先处理后包含，不会出现变量重复定义的错误

~~~jsp
<jsp:include page="receive_param.jsp">
		<jsp:param name="name" value="<%=username%>"/>
		<jsp:param name="info" value="www.mldnjava.cn"/>
	</jsp:include>
~~~

客户端跳转：不可以传递参数，地址栏改变为跳转后的页面地址

~~~html
<a href="forward_demo02.jsp">forward through hyperlink</a>
~~~

服务端跳转：可以传递参数，地址栏不改变，还是跳转前的页面地址，但是内容已是跳转后的页面内容。且跳转属于立即跳转，跳转语句之后的语句不再执行。

~~~jsp
<jsp:forward page="forward_demo02.jsp">
	<jsp:param name="name" value="<%=username%>"/>
	<jsp:param name="info" value="www.mldnjava.cn"/>
</jsp:forward>
~~~

JSP 9个内置对象（常用前5个）：

| No.  |  内置对象   |                  类型                  |                   描述                   |
| :--: | :---------: | :------------------------------------: | :--------------------------------------: |
|  1   | pageContext |     javax.servlet.jsp.PageContext      |              JSP的页面容器               |
|  2   |   request   | javax.servlet.http.HttpServletRequest  |            得到用户的请求信息            |
|  3   |  response   | javax.servlet.http.HttpServletResponse |       服务器向客户端发送的响应信息       |
|  4   |   session   |     javax.servlet.http.HttpSession     |          用来保存每个用户的信息          |
|  5   | application |      javax.servlet.ServletContext      |          表示所有用户的共享信息          |
|  6   |   config    |      javax.servlet.ServletConfig       |                服务器配置                |
|  7   |     out     |      javax.servlet.jsp.JspWriter       |                 页面输出                 |
|  8   |    page     |            java.lang.Object            | 表示从JSP页面中表示出来的一个servlet实例 |
|  9   |  exception  |          java.lang.Throwable           |          表示JSP页面发生的异常           |

pageContext对象：

~~~java
//通过pageContext对象几乎可以取得所有的内置对象
ServletRequest getRequest();
ServletResponse getResponse();
HttpSession getSession();
ServletContext getServletContext();
ServletConfig getServletConfig();
void forward(String relativeUrlPath);
~~~

request对象获取客户端http请求的信息，常用相关接口：

~~~java
void setCharacterEncoding(String env)
String getParameter(String name)
Enumeration<String> getParameterNames()
String getMethod()
String getRemoteAddr()
String getServletPath()
String getContextPath()
Cookie[] getCookies()
Object getAttribute(String name)
void setAttribute(String name, Object o)
~~~

response对象设置响应信息，常用相关接口：

~~~java
void addCookie(Cookie cookie)
void setHeader(String name, String value)
/*
属于客户端跳转，不可以传递request属性，是在所有语句执行完后进行的跳转，跳转后地址栏改变
*/
void sendRedirect(String location)
~~~

session对象保存用户信息：常用于用户登陆验证：

~~~java
//验证用户名，密码后，登陆成功，并保存用户信息
session.setAttribute("username", "xxoo");
//获取session保存的信息
session.getAttribute("username");
//注销当前用户的session相关信息
session.invalidate();
~~~

application对象：

~~~java
//取得绝对路径
application.getRealPath("/");
//this表示当前容器，this.getServletContext()等同于application
this.getServletContext().getRealPath("/");

~~~

config对象：

~~~xml
//取得服务器web.xml配置的参数：config.getInitParameter("leoparamxx")
//将web页面资源放在WEB-INF目录下是最安全的，然后通过映射路径访问
<servlet>
    <servlet-name>leoqiao</servlet-name>
    <jsp-file>/WEB-INF/hello.jsp</jsp-file>
    <init-param>
        <param-name>leoparam1</param-name>
        <param-value>this is first param</param-value>
    </init-param>
    <init-param>
        <param-name>leoparam2</param-name>
        <param-value>this is second param</param-value>
    </init-param>        
</servlet> 
<servlet-mapping>
    <servlet-name>leoqiao</servlet-name>
    <url-pattern>/hello-leo</url-pattern>
</servlet-mapping> 
~~~

JSP 4种属性范围：

pageContext：只在此页面有效，跳转后无效

request：只在一次请求中保存，服务器端跳转后依然有效

session：只在一次会话中保存，无论何种跳转后都有效，但是新开的浏览器无效

application：在整个服务器上保存，所有用户都可以使用

~~~java
//属性操作方法
void setAttribute(String name, Object object)
Object getAttribute(String name)
void removeAttribute(String name)
//通过pageContext.setAttribute(String name, Object value, int scope)可设置四种范围的属性
//PageContext.PAGE_SCOPE
//PageContext.REQUEST_SCOPE
//PageContext.SESSION_SCOPE
//PageContext.APPLICATION_SCOPE    
void setAttribute(String name, Object value, int scope)
~~~



**JSP表达式语言**

~~~
通过JSP表达式语言方便的进行属性输出，语法：${属性name}
JSP表达式语言内置对象：pageScope、requestScope、sessionScope、applicationScope等。例如：${pageScope.属性name}、${pageContext.属性name}、${param.属性name}、${paramValues.属性name[index]}
JSP表达式语言输出集合：${集合name[index或key]}
~~~



**JSP标签**

~~~
helloTag.jsp <---> web.xml <---> helloTag.tld <---> HelloTag.java
1. 实现一个标签处理类HelloTag.java：
	1.1 继承自javax.servlet.jsp.tagext.TagSupport，实现doStartTag、doEndTag、doAfterBody等方法。
	1.2 继承自javax.servlet.jsp.tagext.SimpleTagSupport，实现doTag方法。
	
2. 定义一个标签描述文件helloTag.tld
<?xml version="1.0" encoding="UTF-8"?>
<taglib xmlns="http://java.sun.com/xml/ns/j2ee"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="http://java.sun.com/xml/ns/j2ee http://java.sun.com/xml/ns/j2ee/web-jsptaglibrary_2_1.xsd"
    version="2.1">
    <tlib-version>1.0</tlib-version>
    <short-name>firsttag</short-name>
    <tag>
		<name>hello</name>
		<tag-class>com.test.qj.HelloTag</tag-class>
		<body-content>empty</body-content>
		<attribute>
			<description>The expression to evaluate.</description>
			<name>expression</name>
			<required>true</required>
			<rtexprvalue>true</rtexprvalue>
		</attribute>
    </tag>
</taglib>

3. 在web.xml中配置标签的映射路径（可选）
<web-app xmlns="http://java.sun.com/xml/ns/javaee"
   xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
   xsi:schemaLocation="http://java.sun.com/xml/ns/javaee http://java.sun.com/xml/ns/javaee/web-app_2_5.xsd"
   version="2.5">
	<jsp-config>
		<taglib>
			<taglib-uri>hello_tld_uri</taglib-uri>
			<taglib-location>/WEB-INF/hellotag.tld</taglib-location>
		</taglib>
	</jsp-config>
</web-app>

4. 在jsp文件中使用标签：<%@taglib prefix=“xxoo” uri="taglib_tld_uri" %>

------------------------------------------------------------------------

实际开发不需要自己去实现自定义标签，可以使用第三方的标签库（jar包放tomcat/lib目录；tld文件放webapp/WEB_INF目录，然后在web.xml中配置标签的映射路径） 
~~~



**Java Bean**

~~~txt
Java Bean 是一个具有以下特征的类：
1. 类必须放在一个package下
2. 类必须声明为public class
3. 类中所有属性必须封装为private
4. 需要外部操作的属性需要提供对应的setter、getter（setter和getter命名规范）
5. 至少有一个无参构造函数

JSP 通过标签操作Java Bean，是利用反射机制进行的Java Bean对象的实例化的。

~~~



**DAO设计模式**

~~~
1. Java Bean     	  <-------->   数据库对象
2. DAO Interface 	  <-------->   数据库操作（增删改查）接口
3. DAO Implements     <-------->   数据库操作接口具体实现
4. Database Connection<-------->   具体数据库连接
5. DaoProxy Implements<-------->   代理：连接数据库，选择使用哪个具体的数据库操作接口实现
6. Dao Factory        <-------->   使用哪个代理
~~~



**Servlet**

~~~
1. 自定义Servlet继承自HttpServlet，并实现doGet、doPost、service等方法。
2. 在web.xml中配置映射：
	<servlet>
		<servlet-name>helloservlet</servlet-name>
		<servlet-class>com.test.qj.HelloServlet</servlet-class>
		<load-on-startup>1</load-on-startup>
		 <init-param>
            <param-name>leoparam1</param-name>
            <param-value>this is first param</param-value>
        </init-param>
        <init-param>
            <param-name>leoparam2</param-name>
            <param-value>this is second param</param-value>
        </init-param>
	</servlet>
	<servlet-mapping>
		<servlet-name>helloservlet</servlet-name>
		<url-pattern>/helloservlet</url-pattern>
	</servlet-mapping>
3. Servlet生命周期 - init - doService/doGet/doPost - destroy；Servlet默认第一次使用的时候初始化，也可以配置web.xml - <load-on-startup>1</load-on-startup>，则Tomcat容器启动时初始化。
4. Servlet接收初始化参数 - init(ServletConfig) （会覆盖无参的init方法）- 配置web.xml- <init-param></init-param>。
5. 通过Servlet进行跳转：
	5.1 客户端跳转（无法传递request范围的属性，可以传递session、application范围的属性）：HttpServletResponse -> sendRedirect
	5.2 服务器端跳转（传递request范围的属性）：HttpServletRequest -> getRequestDispatcher -> forward
6. Servlet分三类：
	6.1 简单Servlet：继承自HttpServlet，并实现doGet、doPost、service等方法
	6.2 过滤Servlet：实现javax.servlet.Filter接口，覆写doFilter方法，并配置web.xml实现过滤
	<filter>
		<filter-name>filterdemo</filter-name>
		<filter-class>com.test.qj.FilterDemo</filter-class>
        <init-param>
            <param-name>leoparam</param-name>
            <param-value>this is filter param</param-value>
        </init-param>		
	</filter>
	<filter-mapping>
		<filter-name>filterdemo</filter-name>
		<url-pattern>/*</url-pattern>
	</filter-mapping>
	...(filter配置放在所有servlet配置之前)
	过滤Servlet生命周期：容器启动时初始化，容器关闭时销毁。
	6.3 监听Servlet：实现ServletContextListener、HttpSessionListener、ServletRequestListener等接口，覆写方法，并配置web.xml实现监听特定事件
	...(listener配置放在filter配置之后)
	<listener>
		<listener-class>com.test.qj.ListenerDemo</listener-class>
	</listener>
	...(listener配置放在servlet配置之前)
~~~



**Tomcat数据源配置**

~~~
1. 下载mysql driver jar包：mysql-connector-java-5.1.46-bin.jar 放在Tomcat lib目录下
2. 配置conf/context.xml：
<Context>
        <Resource name="jdbc/mysqlds" auth="Container"
        type="javax.sql.DataSource"
        driverClassName="com.mysql.jdbc.Driver"
        url="jdbc:mysql://localhost:3306/jfinal_demo"
        username="root" password="12345678" 
        maxActive="5" maxIdle="2" maxWait="1000"/>
</Context>
3. 使用数据源
<%@ page contentType="text/html" pageEncoding="GBK" %>
<%@ page import="java.sql.*"%>
<%@ page import="javax.naming.*"%>
<%@ page import="javax.sql.*"%>
<html>
	<head>
	</head>
	<body>
		<%
		try {
			Context ctx = new InitialContext();
			DataSource ds = (DataSource) ctx.lookup("java:comp/env/jdbc/mysqlds");
			Connection conn = ds.getConnection();
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery("select * from blog");
			while(rs.next()) {
		%>
		<h2><%=rs.getString(1)%> ---- <%=rs.getString(2)%></h2>
		<%
			}
		} catch(Exception e) {
			e.printStackTrace();		
		}
		%>
	</body>
</html>
~~~



**AJAX**

~~~
Asynchronous JavaScript and XML: 主要用于页面的局部刷新
核心：通过XMLHttpRequest对象：发送异步请求并处理响应 
~~~



**WEB开发模式**

```
模式一：JSP（显示） + Java Bean（业务对象） + DAO（数据库访问）
```

```
模式二：MVC模式（Model（Java Bean + DAO），View（JSP），Controller（Servlet））
重点在servlet可以通过RequestDispatcher的forward方法将请求和request参数传给JSP
```



**STRUTS**

~~~
struts是MVC理念的一种实现：Model（Java Bean + ActionForm），View（JSP + struts标签），Controller（Action）
~~~

![image-20180722231728599](/Users/qiaojian/Documents/learnGit/markdown/image-struts-dir-structure.png)



![image-20180722232521902](/Users/qiaojian/Documents/learnGit/markdown/image-struts-原理.png)



**WebSocket**

 HTML5支持的新的应用层协议，实现了浏览器与服务器之间的全双工通信。

WebSocket通过HTTP建立连接：具体指的是，客户端通过HTTP请求与服务端协商升级协议。协议升级完成后，后续的数据交换则遵照WebSocket的协议。

1. 客户端发起协议升级请求：

   ~~~
   GET / HTTP/1.1
   Host: localhost:8080
   Origin: http://127.0.0.1:3000
   Connection: Upgrade
   Upgrade: websocket
   Sec-WebSocket-Version: 13
   Sec-WebSocket-Key: w4v7O6xFTi36lq3RNcgctw==
   ~~~

2. 服务端响应协议升级：

   ~~~
   HTTP/1.1 101 Switching Protocols
   Connection:Upgrade
   Upgrade: websocket
   Sec-WebSocket-Accept: Oy4NRAQ13jhfONC7bP8dTKb4PTU=
   ~~~

   

