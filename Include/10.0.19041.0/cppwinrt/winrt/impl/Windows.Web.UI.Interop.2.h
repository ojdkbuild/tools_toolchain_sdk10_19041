// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_Web_UI_Interop_2_H
#define WINRT_Windows_Web_UI_Interop_2_H
#include "winrt/impl/Windows.Web.UI.1.h"
#include "winrt/impl/Windows.Web.UI.Interop.1.h"
namespace winrt::Windows::Web::UI::Interop
{
    struct __declspec(empty_bases) WebViewControl : Windows::Web::UI::IWebViewControl,
        impl::require<WebViewControl, Windows::Web::UI::Interop::IWebViewControlSite, Windows::Web::UI::IWebViewControl2, Windows::Web::UI::Interop::IWebViewControlSite2>
    {
        WebViewControl(std::nullptr_t) noexcept {}
        WebViewControl(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Web::UI::IWebViewControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlAcceleratorKeyPressedEventArgs : Windows::Web::UI::Interop::IWebViewControlAcceleratorKeyPressedEventArgs
    {
        WebViewControlAcceleratorKeyPressedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlAcceleratorKeyPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Web::UI::Interop::IWebViewControlAcceleratorKeyPressedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlMoveFocusRequestedEventArgs : Windows::Web::UI::Interop::IWebViewControlMoveFocusRequestedEventArgs
    {
        WebViewControlMoveFocusRequestedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlMoveFocusRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Web::UI::Interop::IWebViewControlMoveFocusRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlProcess : Windows::Web::UI::Interop::IWebViewControlProcess
    {
        WebViewControlProcess(std::nullptr_t) noexcept {}
        WebViewControlProcess(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Web::UI::Interop::IWebViewControlProcess(ptr, take_ownership_from_abi) {}
        WebViewControlProcess();
        WebViewControlProcess(Windows::Web::UI::Interop::WebViewControlProcessOptions const& processOptions);
    };
    struct __declspec(empty_bases) WebViewControlProcessOptions : Windows::Web::UI::Interop::IWebViewControlProcessOptions
    {
        WebViewControlProcessOptions(std::nullptr_t) noexcept {}
        WebViewControlProcessOptions(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Web::UI::Interop::IWebViewControlProcessOptions(ptr, take_ownership_from_abi) {}
        WebViewControlProcessOptions();
    };
}
#endif
