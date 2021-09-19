// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_Gaming_XboxLive_Storage_0_H
#define WINRT_Windows_Gaming_XboxLive_Storage_0_H
namespace winrt::Windows::Foundation
{
}
namespace winrt::Windows::Foundation::Collections
{
    template <typename T> struct IIterable;
    template <typename K, typename V> struct IMapView;
    struct IPropertySet;
}
namespace winrt::Windows::Storage::Streams
{
    struct IBuffer;
}
namespace winrt::Windows::System
{
    struct User;
}
namespace winrt::Windows::Gaming::XboxLive::Storage
{
    enum class GameSaveErrorStatus : int32_t
    {
        Ok = 0,
        Abort = -2147467260,
        InvalidContainerName = -2138898431,
        NoAccess = -2138898430,
        OutOfLocalStorage = -2138898429,
        UserCanceled = -2138898428,
        UpdateTooBig = -2138898427,
        QuotaExceeded = -2138898426,
        ProvidedBufferTooSmall = -2138898425,
        BlobNotFound = -2138898424,
        NoXboxLiveInfo = -2138898423,
        ContainerNotInSync = -2138898422,
        ContainerSyncFailed = -2138898421,
        UserHasNoXboxLiveInfo = -2138898420,
        ObjectExpired = -2138898419,
    };
    struct IGameSaveBlobGetResult;
    struct IGameSaveBlobInfo;
    struct IGameSaveBlobInfoGetResult;
    struct IGameSaveBlobInfoQuery;
    struct IGameSaveContainer;
    struct IGameSaveContainerInfo;
    struct IGameSaveContainerInfoGetResult;
    struct IGameSaveContainerInfoQuery;
    struct IGameSaveOperationResult;
    struct IGameSaveProvider;
    struct IGameSaveProviderGetResult;
    struct IGameSaveProviderStatics;
    struct GameSaveBlobGetResult;
    struct GameSaveBlobInfo;
    struct GameSaveBlobInfoGetResult;
    struct GameSaveBlobInfoQuery;
    struct GameSaveContainer;
    struct GameSaveContainerInfo;
    struct GameSaveContainerInfoGetResult;
    struct GameSaveContainerInfoQuery;
    struct GameSaveOperationResult;
    struct GameSaveProvider;
    struct GameSaveProviderGetResult;
}
namespace winrt::impl
{
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveContainer>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveProvider>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveBlobGetResult>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfo>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveContainer>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfo>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveProvider>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveProviderGetResult>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus>
    {
        using type = enum_category;
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveBlobGetResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveBlobInfo" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveBlobInfoGetResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveBlobInfoQuery" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveContainer>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveContainer" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveContainerInfo" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveContainerInfoGetResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveContainerInfoQuery" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveOperationResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveProvider>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveProvider" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveProviderGetResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.IGameSaveProviderStatics" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveBlobGetResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveBlobGetResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfo>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveBlobInfo" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveBlobInfoGetResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveBlobInfoQuery" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveContainer>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveContainer" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfo>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveContainerInfo" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveContainerInfoGetResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveContainerInfoQuery" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveOperationResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveProvider>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveProvider" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveProviderGetResult>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveProviderGetResult" };
    };
    template <> struct name<Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus>
    {
        static constexpr auto & value{ L"Windows.Gaming.XboxLive.Storage.GameSaveErrorStatus" };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult>
    {
        static constexpr guid value{ 0x917281E0,0x7201,0x4953,{ 0xAA,0x2C,0x40,0x08,0xF0,0x3A,0xEF,0x45 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo>
    {
        static constexpr guid value{ 0xADD38034,0xBAF0,0x4645,{ 0xB6,0xD0,0x46,0xED,0xAF,0xFB,0x3C,0x2B } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult>
    {
        static constexpr guid value{ 0xC7578582,0x3697,0x42BF,{ 0x98,0x9C,0x66,0x5D,0x92,0x3B,0x52,0x31 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery>
    {
        static constexpr guid value{ 0x9FDD74B2,0xEEEE,0x447B,{ 0xA9,0xD2,0x7F,0x96,0xC0,0xF8,0x32,0x08 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveContainer>
    {
        static constexpr guid value{ 0xC3C08F89,0x563F,0x4ECD,{ 0x9C,0x6F,0x33,0xFD,0x0E,0x32,0x3D,0x10 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo>
    {
        static constexpr guid value{ 0xB7E27300,0x155D,0x4BB4,{ 0xB2,0xBA,0x93,0x03,0x06,0xF3,0x91,0xB5 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult>
    {
        static constexpr guid value{ 0xFFC50D74,0xC581,0x4F9D,{ 0x9E,0x39,0x30,0xA1,0x0C,0x1E,0x4C,0x50 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery>
    {
        static constexpr guid value{ 0x3C94E863,0x6F80,0x4327,{ 0x93,0x27,0xFF,0xC1,0x1A,0xFD,0x42,0xB3 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult>
    {
        static constexpr guid value{ 0xCF0F1A05,0x24A0,0x4582,{ 0x9A,0x55,0xB1,0xBB,0xBB,0x93,0x88,0xD8 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveProvider>
    {
        static constexpr guid value{ 0x90A60394,0x80FE,0x4211,{ 0x97,0xF8,0xA5,0xDE,0x14,0xDD,0x95,0xD2 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult>
    {
        static constexpr guid value{ 0x3AB90816,0xD393,0x4D65,{ 0xAC,0x16,0x41,0xC3,0xE6,0x7A,0xB9,0x45 } };
    };
    template <> struct guid_storage<Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics>
    {
        static constexpr guid value{ 0xD01D3ED0,0x7B03,0x449D,{ 0x8C,0xBD,0x34,0x02,0x84,0x2A,0x10,0x48 } };
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveBlobGetResult>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfo>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveContainer>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveContainer;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfo>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveProvider>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveProvider;
    };
    template <> struct default_interface<Windows::Gaming::XboxLive::Storage::GameSaveProviderGetResult>
    {
        using type = Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult;
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Size(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetBlobInfoAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetBlobInfoWithIndexAndMaxAsync(uint32_t, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetItemCountAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveContainer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Provider(void**) noexcept = 0;
            virtual int32_t __stdcall SubmitUpdatesAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall ReadAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SubmitPropertySetUpdatesAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateBlobInfoQuery(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_TotalSize(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_LastModifiedTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_NeedsSync(bool*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetContainerInfoAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetContainerInfoWithIndexAndMaxAsync(uint32_t, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetItemCountAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
            virtual int32_t __stdcall CreateContainer(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteContainerAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateContainerInfoQuery(void**) noexcept = 0;
            virtual int32_t __stdcall CreateContainerInfoQueryWithName(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetRemainingBytesInQuotaAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContainersChangedSinceLastSync(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForUserAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetSyncOnDemandForUserAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobGetResult
    {
        [[nodiscard]] auto Status() const;
        [[nodiscard]] auto Value() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobGetResult<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfo
    {
        [[nodiscard]] auto Name() const;
        [[nodiscard]] auto Size() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoGetResult
    {
        [[nodiscard]] auto Status() const;
        [[nodiscard]] auto Value() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoGetResult<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoQuery
    {
        auto GetBlobInfoAsync() const;
        auto GetBlobInfoAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const;
        auto GetItemCountAsync() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoQuery<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer
    {
        [[nodiscard]] auto Name() const;
        [[nodiscard]] auto Provider() const;
        auto SubmitUpdatesAsync(param::async_map_view<hstring, Windows::Storage::Streams::IBuffer> const& blobsToWrite, param::async_iterable<hstring> const& blobsToDelete, param::hstring const& displayName) const;
        auto ReadAsync(param::async_map_view<hstring, Windows::Storage::Streams::IBuffer> const& blobsToRead) const;
        auto GetAsync(param::async_iterable<hstring> const& blobsToRead) const;
        auto SubmitPropertySetUpdatesAsync(Windows::Foundation::Collections::IPropertySet const& blobsToWrite, param::async_iterable<hstring> const& blobsToDelete, param::hstring const& displayName) const;
        auto CreateBlobInfoQuery(param::hstring const& blobNamePrefix) const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveContainer>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo
    {
        [[nodiscard]] auto Name() const;
        [[nodiscard]] auto TotalSize() const;
        [[nodiscard]] auto DisplayName() const;
        [[nodiscard]] auto LastModifiedTime() const;
        [[nodiscard]] auto NeedsSync() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoGetResult
    {
        [[nodiscard]] auto Status() const;
        [[nodiscard]] auto Value() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoGetResult<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoQuery
    {
        auto GetContainerInfoAsync() const;
        auto GetContainerInfoAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const;
        auto GetItemCountAsync() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoQuery<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveOperationResult
    {
        [[nodiscard]] auto Status() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveOperationResult<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider
    {
        [[nodiscard]] auto User() const;
        auto CreateContainer(param::hstring const& name) const;
        auto DeleteContainerAsync(param::hstring const& name) const;
        auto CreateContainerInfoQuery() const;
        auto CreateContainerInfoQuery(param::hstring const& containerNamePrefix) const;
        auto GetRemainingBytesInQuotaAsync() const;
        [[nodiscard]] auto ContainersChangedSinceLastSync() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveProvider>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderGetResult
    {
        [[nodiscard]] auto Status() const;
        [[nodiscard]] auto Value() const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderGetResult<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderStatics
    {
        auto GetForUserAsync(Windows::System::User const& user, param::hstring const& serviceConfigId) const;
        auto GetSyncOnDemandForUserAsync(Windows::System::User const& user, param::hstring const& serviceConfigId) const;
    };
    template <> struct consume<Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics>
    {
        template <typename D> using type = consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderStatics<D>;
    };
}
#endif
