
In this code, we're not directly reading file content and attaching to http request. We are passing file name through curl_formadd() function and libcurl will take care of reading and sending file content. This is the recommended and efficient way. You may also add error handling and success response check in code for better code quality. 
Please make sure that you’ve installed the libcurl and linked it properly in your project.
