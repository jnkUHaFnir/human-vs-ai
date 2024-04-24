    CString boundary = "-------------------------------7d8b32060180";
			CString postBody;
			postBody.AppendFormat("\r\n--%s\r\n", boundary);
			postBody.AppendFormat("Content-Disposition: form-data; name=\"name\"\n\n%s", name);
			postBody.AppendFormat("\n--%s\r\n", boundary);
			postBody.AppendFormat("Content-Disposition: form-data; name=\"email\"\n\n\n\r\r\n%s\n", emailID);
			postBody.AppendFormat("\r\n--%s\r\n", boundary);
			postBody.AppendFormat("Content-Disposition: form-data; name=\"comments\"\n\n\r\r\n%s\n", comment);
			postBody.AppendFormat("\r\n--%s\r\n", boundary);
			postBody.AppendFormat("Content-Disposition: form-data; name=\"subject\"\n\n\r\r\n%s\n", subjectLine);	
			postBody.AppendFormat("\r\n--%s\r\n", boundary);
			//filePath= "C:\\Users\\Mahantesh\\Desktop\\gan.zip";
			int  totalMsgLen = 0, len = 0; 
			BYTE* MyHttpResponse ;
			if (!filePath.IsEmpty())
			{
				CString buff;
				TCHAR* pBuff = _T("");
				CFile vidFile; 
				if (vidFile.Open(filePath, CFile::modeRead))			
				{
					len = vidFile.GetLength();
					pBuff = buff.GetBuffer(len+1);
					vidFile.Read(pBuff, len);
					pBuff[len] = '\0';
					vidFile.Close();
					postBody.AppendFormat("Content-Disposition: form-data; name=\"datafile\"; filename=\"%s\"; \r\n\n", filePath);	
					//postBody.AppendFormat("\r\n--%s--\r\n", boundary);
				}		
				totalMsgLen = postBody.GetLength() + strlen("\n--" +boundary+ "\r\n") + len;
				MyHttpResponse = new BYTE[totalMsgLen];  //create enough buffer memory
				memset(MyHttpResponse, 0x00, totalMsgLen);
				memcpy(MyHttpResponse, postBody.GetString(), postBody.GetLength()); //write header to final buffer
				memcpy(MyHttpResponse + postBody.GetLength(), pBuff, len); //add file contents
				memcpy(MyHttpResponse + postBody.GetLength()+ len, "\n--" + boundary+ "--\r\n", strlen("\n--" +boundary+ "--\r\n")); 
				MyHttpResponse[totalMsgLen + 1] = '\0';
			}
			CString strHeaderCS;
			strHeaderCS.AppendFormat("Content-Type:multipart/form-data; boundary=%s\r\n", boundary);
			strHeaderCS.AppendFormat("Accept-Charset:ISO-8859-15, utf-8;q=0.66, *;q=0.66\r\n");
			strHeaderCS.AppendFormat("Keep-Alive:5000\r\n");
			strHeaderCS.AppendFormat("Accept-Language:en\r\n");
			strHeaderCS.AppendFormat("Accept-Encoding:gzip, deflate\r\n");
			strHeaderCS.AppendFormat("User-Agent:Mozilla/4.0 (Windows; U; Windows Vista;)\r\n");
			strHeaderCS.AppendFormat("Accept:text/xml,application/xml,application/xhtml+xml, application/vid,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5\r\n");
			strHeaderCS.AppendFormat("Content-Length:%d\r\n", totalMsgLen);
			strHeaderCS.AppendFormat("Connection:keep-alive\r\n");
			strHeaderCS.AppendFormat("Host:www.filemagic.org\r\n");
			
			CString strObject, server;
			INTERNET_PORT port;
			DWORD dwServiceType;
			USES_CONVERSION;			
			AfxParseURL(strURL, dwServiceType, server, strObject, port);
			HINTERNET hINetOpen, hINetConnect, hINetRequest;
			try
			{
				hINetOpen = InternetOpen(_T("SplashID"),  INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);//AK
				if (hINetOpen != NULL){
					hINetConnect = InternetConnect(hINetOpen, server, INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, INTERNET_FLAG_IDN_PROXY, 0); 
					if (hINetConnect != NULL){
						hINetRequest = HttpOpenRequest(hINetConnect, _T("POST"), strObject, HTTP_VERSION, 0, NULL,  INTERNET_FLAG_RELOAD |INTERNET_FLAG_IGNORE_CERT_CN_INVALID | SECURITY_FLAG_IGNORE_UNKNOWN_CA | INTERNET_FLAG_IGNORE_CERT_DATE_INVALID | INTERNET_FLAG_NO_AUTO_REDIRECT | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_CACHE_WRITE, 0);
						if (hINetRequest != NULL){
							if(HttpSendRequest(hINetRequest, strHeaderCS, strHeaderCS.GetLength(), (LPVOID) MyHttpResponse, totalMsgLen)) {
								CString sBodyText;
								DWORD nRead= 1024;
								char szBuf[ 1025 ] = {0};
								while ( nRead > 0 ) {
									// Read in a temporary buffer
									InternetReadFile(hINetRequest, szBuf, 1024, &nRead);
									szBuf[nRead] = '\0';
									sBodyText += szBuf;
								}
							}						
						}
					}
				}
			}
			catch(...)
			{
			}
			/*if (strPostData)
			{
				strPostData = '\0';
				delete strPostData;
			}*/
			if(hINetOpen)
			{
				InternetCloseHandle(hINetOpen);
				hINetOpen = NULL;
			}
			if (hINetConnect)
			{
				InternetCloseHandle(hINetConnect);
				hINetConnect = NULL;
			}
			if (hINetRequest)
			{
				InternetCloseHandle(hINetRequest);
				hINetRequest = NULL;
			}