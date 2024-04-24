    #include <tchar.h>
    #include <windows.h>
    #include <d3d9.h>
    #include <d3dx9.h>
    #include <iostream>
    
    HRESULT capture(IDirect3DDevice9* d3d9, void* buffer, int& width, int& height, D3DFORMAT format);
    
    
    void onUpdate(HWND hwnd, IDirect3D9* d3d9, IDirect3DDevice9* d3ddev9, D3DFORMAT format)
    {
        d3ddev9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);
        d3ddev9->BeginScene();
        //All drawing goes here..
        d3ddev9->EndScene();
    
    
        RECT rect;
        GetClientRect(hwnd, &rect);
    
        int width = rect.right - rect.left, height = rect.bottom - rect.top;
        unsigned char* buffer = new unsigned char[width * height * 4];
        capture(d3ddev9, buffer, width, height, format);
    
        unsigned char* px = buffer;
    
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                unsigned char B = *px++;
                unsigned char G = *px++;
                unsigned char R = *px++;
                unsigned char A = *px++;
    
                if (D3DCOLOR_XRGB(R, G, B) != D3DCOLOR_XRGB(0, 40, 100))
                {
                    std::cout<<std::boolalpha<<"FAILED.. Colour differs from original background..\n";
                }
            }
        }
    
        delete[] buffer;
    
        d3ddev9->Present(NULL, NULL, NULL, NULL);  //Swaps the back and front buffers. Displays all drawing on the screen..
    }
    
    int onDisplay(HWND hwnd)
    {
        IDirect3D9* d3d9 = NULL;
        IDirect3DDevice9* d3ddev9 = NULL;
        D3DPRESENT_PARAMETERS Parameters = {0};
        d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
    
        D3DDISPLAYMODE* dispMode = new D3DDISPLAYMODE();
        d3d9->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, dispMode);
    
        Parameters.Windowed = true;
        Parameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
        Parameters.hDeviceWindow = hwnd;
        Parameters.BackBufferFormat = dispMode->Format;
        d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &Parameters, &d3ddev9);
        delete dispMode;
    
        MSG messages;
        ShowWindow(hwnd, SW_SHOW);
    
        while(true)
        {
            if (PeekMessage(&messages, NULL, 0, 0, PM_REMOVE) > 0)
            {
                if (messages.message != WM_QUIT)
                {
                    TranslateMessage(&messages);
                    DispatchMessageW(&messages);
                    continue;
                }
                break;
            }
            else
            {
                onUpdate(hwnd, d3d9, d3ddev9, Parameters.BackBufferFormat);
            }
        }
    
        if (d3ddev9) d3ddev9->Release();
        if (d3d9) d3d9->Release();
        return messages.wParam;
    }
    
    
    LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch(message)
        {
            case WM_DESTROY:
                PostQuitMessage(0);
                break;
            default:
                return DefWindowProc (hwnd, message, wParam, lParam);
        }
    
        return 0;
    }
    
    int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
    {
        WNDCLASSEX wincl;
        wincl.hInstance = hThisInstance;
        wincl.lpszClassName = "D3DWindow";
        wincl.lpfnWndProc = WindowProcedure;
        wincl.style = CS_DBLCLKS;
        wincl.cbSize = sizeof (WNDCLASSEX);
        wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
        wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
        wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
        wincl.lpszMenuName = NULL;
        wincl.cbClsExtra = 0;
        wincl.cbWndExtra = 0;
        wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    
        if (!RegisterClassEx (&wincl)) return 0;
        HWND hwnd = CreateWindowEx (0, "D3DWindow", "D3D9: Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 544, 375, HWND_DESKTOP, NULL, hThisInstance, NULL);
        return onDisplay(hwnd);
    }
    
    
    HRESULT capture(IDirect3DDevice9* d3ddev9, void* buffer, int& width, int& height, D3DFORMAT format)
    {
        IDirect3DSurface9* RenderTarget = NULL;
        IDirect3DSurface9* DestTarget = NULL;
        HRESULT result = d3ddev9->GetRenderTarget(0, &RenderTarget);
    
        if (result == S_OK)
        {
            result = d3ddev9->CreateOffscreenPlainSurface(width, height, format, D3DPOOL_SYSTEMMEM, &DestTarget, NULL);
            result = d3ddev9->GetRenderTargetData(RenderTarget, DestTarget);
    
            D3DLOCKED_RECT rect;
            DestTarget->LockRect(&rect, 0, D3DLOCK_READONLY);
            memcpy(buffer, rect.pBits, width * height * 4);
            DestTarget->UnlockRect();
        }
    
        if (RenderTarget) RenderTarget->Release();
        if (DestTarget) DestTarget->Release();
        return result;
    }