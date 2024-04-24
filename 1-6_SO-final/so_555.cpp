    HRESULT CloseWindowsExplorerWindowsForDrive(LPCTSTR pStrPath)
    {
    	//Closes all Windows Explorer windows for a specific drive
    	//'pStrPath' = path somewhere on the drive
    	//RETURN:
    	//		= S_OK if done
    	CoInitialize(NULL);
    
    	HRESULT hr;
    
    	TCHAR buffVolPath[MAX_PATH];
    	buffVolPath[0] = 0;
    	if(GetVolumePathName(pStrPath, buffVolPath, MAX_PATH))
    	{
    		int nLnVolPath = lstrlen(buffVolPath);
    
    		IShellWindows* pISW = NULL;
    
    		hr = CoCreateInstance(CLSID_ShellWindows, NULL, CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER,
    			IID_IShellWindows, (void**) &pISW);
    		if (SUCCEEDED(hr))
    		{
    			long nCount;
    			if(SUCCEEDED(hr = pISW->get_Count(&nCount)))
    			{
    				for(int i = nCount - 1; i >= 0; i--)
    				{
    					CComPtr<IDispatch> pIDisp;
    					CComVariant v_i(i);
    					if(SUCCEEDED(hr = pISW->Item(v_i, &pIDisp)))
    					{
    						CComPtr<IWebBrowser2> pIWB2;
    						if(SUCCEEDED(pIDisp->QueryInterface(IID_IWebBrowser2, (void**)&pIWB2)))
    						{
    							CComPtr<IServiceProvider> pISP;
    							if(SUCCEEDED(pIDisp->QueryInterface(IID_IServiceProvider, (void**)&pISP)))
    							{
    								CComPtr<IShellBrowser> pIShBrswr;
    								if(SUCCEEDED(hr= pISP->QueryService(SID_STopLevelBrowser, IID_IShellBrowser, (void**)&pIShBrswr)))
    								{
    									CComPtr<IShellView> pIShView;
    									if(SUCCEEDED(hr = pIShBrswr->QueryActiveShellView(&pIShView)))
    									{
    										CComPtr<IFolderView> pIFV;
    										if(SUCCEEDED(hr = pIShView->QueryInterface(IID_IFolderView, (void**)&pIFV)))
    										{
    											CComPtr<IPersistFolder2> pIPF2;
    											if(SUCCEEDED(hr = pIFV->GetFolder(IID_IPersistFolder2, (void**)&pIPF2)))
    											{
    												LPITEMIDLIST pidlFolder = NULL;
    												if(SUCCEEDED(hr = pIPF2->GetCurFolder(&pidlFolder)))
    												{
    													LPCITEMIDLIST pidlChild = NULL;
    													CComPtr<IShellFolder> pIShFldr;
    													if(SUCCEEDED(::SHBindToParent(pidlFolder, IID_IShellFolder, (void**)&pIShFldr, &pidlChild)))
    													{
    														ULONG attrs = SFGAO_FILESYSTEM;
    														if(SUCCEEDED(hr = pIShFldr->GetAttributesOf(1, &pidlChild, &attrs)))
    														{
    															if(attrs & SFGAO_FILESYSTEM)
    															{
    																STRRET srt;
    																if(SUCCEEDED(hr = pIShFldr->GetDisplayNameOf(pidlChild, SHGDN_FORPARSING, &srt)))
    																{
    																	LPWSTR pStrFileName = NULL;
    																	if(SUCCEEDED(hr = StrRetToStr(&srt, pidlChild, &pStrFileName)))
    																	{
    																		//Compare to our path
    																		if(lstrlen(pStrFileName) >= nLnVolPath &&
    																			::CompareString(LOCALE_USER_DEFAULT, NORM_IGNORECASE,
    																			buffVolPath, nLnVolPath,
    																			pStrFileName, nLnVolPath) == CSTR_EQUAL)
    																		{
    																			//Close it
    																			hr = pIWB2->Quit();
    																		}
    																	}
    
    																	if(pStrFileName)
    																	{
    																		CoTaskMemFree(pStrFileName);
    																		pStrFileName = NULL;
    																	}
    
    																	//Free mem (if StrRetToStr() hasn't done it)
    																	if(srt.pOleStr)
    																	{
    																		CoTaskMemFree(srt.pOleStr);
    																	}
    																}
    															}
    														}
    													}
    
    													if(pidlChild)
    													{
    														CoTaskMemFree((LPVOID)pidlChild);
    														pidlChild = NULL;
    													}
    												}
    
    												if(pidlFolder)
    												{
    													CoTaskMemFree(pidlFolder);
    													pidlFolder = NULL;
    												}
    											}
    										}
    									}
    								}
    							}
    						}
    					}
    				}
    			}
    
    			pISW->Release();
    		}
    	}
    	else
    		hr = E_INVALIDARG;
    
    	CoUninitialize();
    
    	return hr;
    }