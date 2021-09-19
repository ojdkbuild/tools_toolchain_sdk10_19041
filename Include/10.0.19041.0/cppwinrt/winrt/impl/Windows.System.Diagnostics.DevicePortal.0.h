// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_System_Diagnostics_DevicePortal_0_H
#define WINRT_Windows_System_Diagnostics_DevicePortal_0_H
namespace winrt::Windows::ApplicationModel::AppService
{
    struct AppServiceConnection;
}
namespace winrt::Windows::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    template <typename TSender, typename TResult> struct TypedEventHandler;
}
namespace winrt::Windows::Networking::Sockets
{
    enum class MessageWebSocketReceiveMode : int32_t;
    struct ServerMessageWebSocket;
    struct ServerStreamWebSocket;
    enum class SocketMessageType : int32_t;
}
namespace winrt::Windows::Web::Http
{
    struct HttpRequestMessage;
    struct HttpResponseMessage;
}
namespace winrt::Windows::System::Diagnostics::DevicePortal
{
    enum class DevicePortalConnectionClosedReason : int32_t
    {
        Unknown = 0,
        ResourceLimitsExceeded = 1,
        ProtocolError = 2,
        NotAuthorized = 3,
        UserNotPresent = 4,
        ServiceTerminated = 5,
    };
    struct IDevicePortalConnection;
    struct IDevicePortalConnectionClosedEventArgs;
    struct IDevicePortalConnectionRequestReceivedEventArgs;
    struct IDevicePortalConnectionStatics;
    struct IDevicePortalWebSocketConnection;
    struct IDevicePortalWebSocketConnectionRequestReceivedEventArgs;
    struct DevicePortalConnection;
    struct DevicePortalConnectionClosedEventArgs;
    struct DevicePortalConnectionRequestReceivedEventArgs;
}
namespace winrt::impl
{
    template <> struct category<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::System::Diagnostics::DevicePortal::DevicePortalConnection>
    {
        using type = class_category;
    };
    template <> struct category<Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs>
    {
        using type = class_category;
    };
    template <> struct category<Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs>
    {
        using type = class_category;
    };
    template <> struct category<Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedReason>
    {
        using type = enum_category;
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.IDevicePortalConnection" };
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.IDevicePortalConnectionClosedEventArgs" };
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.IDevicePortalConnectionRequestReceivedEventArgs" };
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.IDevicePortalConnectionStatics" };
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.IDevicePortalWebSocketConnection" };
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.IDevicePortalWebSocketConnectionRequestReceivedEventArgs" };
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::DevicePortalConnection>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.DevicePortalConnection" };
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.DevicePortalConnectionClosedEventArgs" };
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.DevicePortalConnectionRequestReceivedEventArgs" };
    };
    template <> struct name<Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedReason>
    {
        static constexpr auto & value{ L"Windows.System.Diagnostics.DevicePortal.DevicePortalConnectionClosedReason" };
    };
    template <> struct guid_storage<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection>
    {
        static constexpr guid value{ 0x0F447F51,0x1198,0x4DA1,{ 0x8D,0x54,0xBD,0xEF,0x39,0x3E,0x09,0xB6 } };
    };
    template <> struct guid_storage<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>
    {
        static constexpr guid value{ 0xFCF70E38,0x7032,0x428C,{ 0x9F,0x50,0x94,0x5C,0x15,0xA9,0xF0,0xCB } };
    };
    template <> struct guid_storage<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>
    {
        static constexpr guid value{ 0x64DAE045,0x6FDA,0x4459,{ 0x9E,0xBD,0xEC,0xCE,0x22,0xE3,0x85,0x59 } };
    };
    template <> struct guid_storage<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>
    {
        static constexpr guid value{ 0x4BBE31E7,0xE9B9,0x4645,{ 0x8F,0xED,0xA5,0x3E,0xEA,0x0E,0xDB,0xD6 } };
    };
    template <> struct guid_storage<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>
    {
        static constexpr guid value{ 0x67657920,0xD65A,0x42F0,{ 0xAE,0xF4,0x78,0x78,0x08,0x09,0x8B,0x7B } };
    };
    template <> struct guid_storage<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        static constexpr guid value{ 0x79FDCABA,0x175C,0x4739,{ 0x9F,0x74,0xDD,0xA7,0x97,0xC3,0x5B,0x3F } };
    };
    template <> struct default_interface<Windows::System::Diagnostics::DevicePortal::DevicePortalConnection>
    {
        using type = Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection;
    };
    template <> struct default_interface<Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs>
    {
        using type = Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs;
    };
    template <> struct default_interface<Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs>
    {
        using type = Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs;
    };
    template <> struct abi<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_Closed(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Closed(winrt::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RequestReceived(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RequestReceived(winrt::event_token) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RequestMessage(void**) noexcept = 0;
            virtual int32_t __stdcall get_ResponseMessage(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForAppServiceConnection(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetServerMessageWebSocketForRequest(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetServerMessageWebSocketForRequest2(void*, int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetServerMessageWebSocketForRequest3(void*, int32_t, void*, uint32_t, uint32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetServerStreamWebSocketForRequest(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetServerStreamWebSocketForRequest2(void*, void*, uint32_t, bool, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsWebSocketUpgradeRequest(bool*) noexcept = 0;
            virtual int32_t __stdcall get_WebSocketProtocolsRequested(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection
    {
        auto Closed(Windows::Foundation::TypedEventHandler<Windows::System::Diagnostics::DevicePortal::DevicePortalConnection, Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs> const& handler) const;
        using Closed_revoker = impl::event_revoker<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection, &impl::abi_t<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection>::remove_Closed>;
        Closed_revoker Closed(auto_revoke_t, Windows::Foundation::TypedEventHandler<Windows::System::Diagnostics::DevicePortal::DevicePortalConnection, Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs> const& handler) const;
        auto Closed(winrt::event_token const& token) const noexcept;
        auto RequestReceived(Windows::Foundation::TypedEventHandler<Windows::System::Diagnostics::DevicePortal::DevicePortalConnection, Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs> const& handler) const;
        using RequestReceived_revoker = impl::event_revoker<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection, &impl::abi_t<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection>::remove_RequestReceived>;
        RequestReceived_revoker RequestReceived(auto_revoke_t, Windows::Foundation::TypedEventHandler<Windows::System::Diagnostics::DevicePortal::DevicePortalConnection, Windows::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs> const& handler) const;
        auto RequestReceived(winrt::event_token const& token) const noexcept;
    };
    template <> struct consume<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnection>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionClosedEventArgs
    {
        [[nodiscard]] auto Reason() const;
    };
    template <> struct consume<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionClosedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionRequestReceivedEventArgs
    {
        [[nodiscard]] auto RequestMessage() const;
        [[nodiscard]] auto ResponseMessage() const;
    };
    template <> struct consume<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionRequestReceivedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionStatics
    {
        auto GetForAppServiceConnection(Windows::ApplicationModel::AppService::AppServiceConnection const& appServiceConnection) const;
    };
    template <> struct consume<Windows::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnection
    {
        auto GetServerMessageWebSocketForRequest(Windows::Web::Http::HttpRequestMessage const& request) const;
        auto GetServerMessageWebSocketForRequest(Windows::Web::Http::HttpRequestMessage const& request, Windows::Networking::Sockets::SocketMessageType const& messageType, param::hstring const& protocol) const;
        auto GetServerMessageWebSocketForRequest(Windows::Web::Http::HttpRequestMessage const& request, Windows::Networking::Sockets::SocketMessageType const& messageType, param::hstring const& protocol, uint32_t outboundBufferSizeInBytes, uint32_t maxMessageSize, Windows::Networking::Sockets::MessageWebSocketReceiveMode const& receiveMode) const;
        auto GetServerStreamWebSocketForRequest(Windows::Web::Http::HttpRequestMessage const& request) const;
        auto GetServerStreamWebSocketForRequest(Windows::Web::Http::HttpRequestMessage const& request, param::hstring const& protocol, uint32_t outboundBufferSizeInBytes, bool noDelay) const;
    };
    template <> struct consume<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnection<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnectionRequestReceivedEventArgs
    {
        [[nodiscard]] auto IsWebSocketUpgradeRequest() const;
        [[nodiscard]] auto WebSocketProtocolsRequested() const;
        auto GetDeferral() const;
    };
    template <> struct consume<Windows::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnectionRequestReceivedEventArgs<D>;
    };
}
#endif