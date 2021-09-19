// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_Devices_Bluetooth_Advertisement_0_H
#define WINRT_Windows_Devices_Bluetooth_Advertisement_0_H
namespace winrt::Windows::Devices::Bluetooth
{
    enum class BluetoothAddressType : int32_t;
    enum class BluetoothError : int32_t;
    struct BluetoothSignalStrengthFilter;
}
namespace winrt::Windows::Foundation
{
    struct EventRegistrationToken;
    template <typename T> struct IReference;
    template <typename TSender, typename TResult> struct TypedEventHandler;
}
namespace winrt::Windows::Storage::Streams
{
    struct IBuffer;
}
namespace winrt::Windows::Devices::Bluetooth::Advertisement
{
    enum class BluetoothLEAdvertisementFlags : uint32_t
    {
        None = 0,
        LimitedDiscoverableMode = 0x1,
        GeneralDiscoverableMode = 0x2,
        ClassicNotSupported = 0x4,
        DualModeControllerCapable = 0x8,
        DualModeHostCapable = 0x10,
    };
    enum class BluetoothLEAdvertisementPublisherStatus : int32_t
    {
        Created = 0,
        Waiting = 1,
        Started = 2,
        Stopping = 3,
        Stopped = 4,
        Aborted = 5,
    };
    enum class BluetoothLEAdvertisementType : int32_t
    {
        ConnectableUndirected = 0,
        ConnectableDirected = 1,
        ScannableUndirected = 2,
        NonConnectableUndirected = 3,
        ScanResponse = 4,
        Extended = 5,
    };
    enum class BluetoothLEAdvertisementWatcherStatus : int32_t
    {
        Created = 0,
        Started = 1,
        Stopping = 2,
        Stopped = 3,
        Aborted = 4,
    };
    enum class BluetoothLEScanningMode : int32_t
    {
        Passive = 0,
        Active = 1,
        None = 2,
    };
    struct IBluetoothLEAdvertisement;
    struct IBluetoothLEAdvertisementBytePattern;
    struct IBluetoothLEAdvertisementBytePatternFactory;
    struct IBluetoothLEAdvertisementDataSection;
    struct IBluetoothLEAdvertisementDataSectionFactory;
    struct IBluetoothLEAdvertisementDataTypesStatics;
    struct IBluetoothLEAdvertisementFilter;
    struct IBluetoothLEAdvertisementPublisher;
    struct IBluetoothLEAdvertisementPublisher2;
    struct IBluetoothLEAdvertisementPublisherFactory;
    struct IBluetoothLEAdvertisementPublisherStatusChangedEventArgs;
    struct IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2;
    struct IBluetoothLEAdvertisementReceivedEventArgs;
    struct IBluetoothLEAdvertisementReceivedEventArgs2;
    struct IBluetoothLEAdvertisementWatcher;
    struct IBluetoothLEAdvertisementWatcher2;
    struct IBluetoothLEAdvertisementWatcherFactory;
    struct IBluetoothLEAdvertisementWatcherStoppedEventArgs;
    struct IBluetoothLEManufacturerData;
    struct IBluetoothLEManufacturerDataFactory;
    struct BluetoothLEAdvertisement;
    struct BluetoothLEAdvertisementBytePattern;
    struct BluetoothLEAdvertisementDataSection;
    struct BluetoothLEAdvertisementDataTypes;
    struct BluetoothLEAdvertisementFilter;
    struct BluetoothLEAdvertisementPublisher;
    struct BluetoothLEAdvertisementPublisherStatusChangedEventArgs;
    struct BluetoothLEAdvertisementReceivedEventArgs;
    struct BluetoothLEAdvertisementWatcher;
    struct BluetoothLEAdvertisementWatcherStoppedEventArgs;
    struct BluetoothLEManufacturerData;
}
namespace winrt::impl
{
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher2>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs2>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher2>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataTypes>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags>
    {
        using type = enum_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus>
    {
        using type = enum_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementType>
    {
        using type = enum_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStatus>
    {
        using type = enum_category;
    };
    template <> struct category<Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode>
    {
        using type = enum_category;
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisement" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementBytePattern" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementBytePatternFactory" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementDataSection" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementDataSectionFactory" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementDataTypesStatics" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementFilter" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementPublisher" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher2>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementPublisher2" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementPublisherFactory" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementPublisherStatusChangedEventArgs" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementReceivedEventArgs" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs2>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementReceivedEventArgs2" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementWatcher" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher2>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementWatcher2" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementWatcherFactory" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEAdvertisementWatcherStoppedEventArgs" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEManufacturerData" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.IBluetoothLEManufacturerDataFactory" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisement" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementBytePattern" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementDataSection" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataTypes>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementDataTypes" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementFilter" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisher" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisherStatusChangedEventArgs" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementReceivedEventArgs" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcher" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcherStoppedEventArgs" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEManufacturerData" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementFlags" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisherStatus" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementType>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementType" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStatus>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcherStatus" };
    };
    template <> struct name<Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode>
    {
        static constexpr auto & value{ L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEScanningMode" };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>
    {
        static constexpr guid value{ 0x066FB2B7,0x33D1,0x4E7D,{ 0x83,0x67,0xCF,0x81,0xD0,0xF7,0x96,0x53 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>
    {
        static constexpr guid value{ 0xFBFAD7F2,0xB9C5,0x4A08,{ 0xBC,0x51,0x50,0x2F,0x8E,0xF6,0x8A,0x79 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory>
    {
        static constexpr guid value{ 0xC2E24D73,0xFD5C,0x4EC3,{ 0xBE,0x2A,0x9C,0xA6,0xFA,0x11,0xB7,0xBD } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>
    {
        static constexpr guid value{ 0xD7213314,0x3A43,0x40F9,{ 0xB6,0xF0,0x92,0xBF,0xEF,0xC3,0x4A,0xE3 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory>
    {
        static constexpr guid value{ 0xE7A40942,0xA845,0x4045,{ 0xBF,0x7E,0x3E,0x99,0x71,0xDB,0x8A,0x6B } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics>
    {
        static constexpr guid value{ 0x3BB6472F,0x0606,0x434B,{ 0xA7,0x6E,0x74,0x15,0x9F,0x06,0x84,0xD3 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>
    {
        static constexpr guid value{ 0x131EB0D3,0xD04E,0x47B1,{ 0x83,0x7E,0x49,0x40,0x5B,0xF6,0xF8,0x0F } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>
    {
        static constexpr guid value{ 0xCDE820F9,0xD9FA,0x43D6,{ 0xA2,0x64,0xDD,0xD8,0xB7,0xDA,0x8B,0x78 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher2>
    {
        static constexpr guid value{ 0xFBDB545E,0x56F1,0x510F,{ 0xA4,0x34,0x21,0x7F,0xBD,0x9E,0x7B,0xD2 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory>
    {
        static constexpr guid value{ 0x5C5F065E,0xB863,0x4981,{ 0xA1,0xAF,0x1C,0x54,0x4D,0x8B,0x0C,0x0D } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>
    {
        static constexpr guid value{ 0x09C2BD9F,0x2DFF,0x4B23,{ 0x86,0xEE,0x0D,0x14,0xFB,0x94,0xAE,0xAE } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2>
    {
        static constexpr guid value{ 0x8F62790E,0xDC88,0x5C8B,{ 0xB3,0x4E,0x10,0xB3,0x21,0x85,0x0F,0x88 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>
    {
        static constexpr guid value{ 0x27987DDF,0xE596,0x41BE,{ 0x8D,0x43,0x9E,0x67,0x31,0xD4,0xA9,0x13 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs2>
    {
        static constexpr guid value{ 0x12D9C87B,0x0399,0x5F0E,{ 0xA3,0x48,0x53,0xB0,0x2B,0x6B,0x16,0x2E } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>
    {
        static constexpr guid value{ 0xA6AC336F,0xF3D3,0x4297,{ 0x8D,0x6C,0xC8,0x1E,0xA6,0x62,0x3F,0x40 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher2>
    {
        static constexpr guid value{ 0x01BF26BC,0xB164,0x5805,{ 0x90,0xA3,0xE8,0xA7,0x99,0x7F,0xF2,0x25 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory>
    {
        static constexpr guid value{ 0x9AAF2D56,0x39AC,0x453E,{ 0xB3,0x2A,0x85,0xC6,0x57,0xE0,0x17,0xF1 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs>
    {
        static constexpr guid value{ 0xDD40F84D,0xE7B9,0x43E3,{ 0x9C,0x04,0x06,0x85,0xD0,0x85,0xFD,0x8C } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>
    {
        static constexpr guid value{ 0x912DBA18,0x6963,0x4533,{ 0xB0,0x61,0x46,0x94,0xDA,0xFB,0x34,0xE5 } };
    };
    template <> struct guid_storage<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory>
    {
        static constexpr guid value{ 0xC09B39F8,0x319A,0x441E,{ 0x8D,0xE5,0x66,0xA8,0x1E,0x87,0x7A,0x6C } };
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement;
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern;
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection;
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter;
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher;
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs;
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs;
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher;
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs;
    };
    template <> struct default_interface<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData>
    {
        using type = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData;
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Flags(void**) noexcept = 0;
            virtual int32_t __stdcall put_Flags(void*) noexcept = 0;
            virtual int32_t __stdcall get_LocalName(void**) noexcept = 0;
            virtual int32_t __stdcall put_LocalName(void*) noexcept = 0;
            virtual int32_t __stdcall get_ServiceUuids(void**) noexcept = 0;
            virtual int32_t __stdcall get_ManufacturerData(void**) noexcept = 0;
            virtual int32_t __stdcall get_DataSections(void**) noexcept = 0;
            virtual int32_t __stdcall GetManufacturerDataByCompanyId(uint16_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetSectionsByType(uint8_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DataType(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall put_DataType(uint8_t) noexcept = 0;
            virtual int32_t __stdcall get_Offset(int16_t*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(int16_t) noexcept = 0;
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall put_Data(void*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(uint8_t, int16_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DataType(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall put_DataType(uint8_t) noexcept = 0;
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall put_Data(void*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(uint8_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Flags(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_IncompleteService16BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_CompleteService16BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_IncompleteService32BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_CompleteService32BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_IncompleteService128BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_CompleteService128BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_ShortenedLocalName(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_CompleteLocalName(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_TxPowerLevel(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_SlaveConnectionIntervalRange(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_ServiceSolicitation16BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_ServiceSolicitation32BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_ServiceSolicitation128BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_ServiceData16BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_ServiceData32BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_ServiceData128BitUuids(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_PublicTargetAddress(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_RandomTargetAddress(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_Appearance(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_AdvertisingInterval(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_ManufacturerSpecificData(uint8_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Advertisement(void**) noexcept = 0;
            virtual int32_t __stdcall put_Advertisement(void*) noexcept = 0;
            virtual int32_t __stdcall get_BytePatterns(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Advertisement(void**) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
            virtual int32_t __stdcall add_StatusChanged(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StatusChanged(winrt::event_token) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PreferredTransmitPowerLevelInDBm(void**) noexcept = 0;
            virtual int32_t __stdcall put_PreferredTransmitPowerLevelInDBm(void*) noexcept = 0;
            virtual int32_t __stdcall get_UseExtendedAdvertisement(bool*) noexcept = 0;
            virtual int32_t __stdcall put_UseExtendedAdvertisement(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsAnonymous(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsAnonymous(bool) noexcept = 0;
            virtual int32_t __stdcall get_IncludeTransmitPowerLevel(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncludeTransmitPowerLevel(bool) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Error(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SelectedTransmitPowerLevelInDBm(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RawSignalStrengthInDBm(int16_t*) noexcept = 0;
            virtual int32_t __stdcall get_BluetoothAddress(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_AdvertisementType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Timestamp(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Advertisement(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BluetoothAddressType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TransmitPowerLevelInDBm(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsAnonymous(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsConnectable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsScannable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDirected(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsScanResponse(bool*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MinSamplingInterval(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxSamplingInterval(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_MinOutOfRangeTimeout(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxOutOfRangeTimeout(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ScanningMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ScanningMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SignalStrengthFilter(void**) noexcept = 0;
            virtual int32_t __stdcall put_SignalStrengthFilter(void*) noexcept = 0;
            virtual int32_t __stdcall get_AdvertisementFilter(void**) noexcept = 0;
            virtual int32_t __stdcall put_AdvertisementFilter(void*) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
            virtual int32_t __stdcall add_Received(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Received(winrt::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Stopped(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Stopped(winrt::event_token) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AllowExtendedAdvertisements(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AllowExtendedAdvertisements(bool) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Error(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CompanyId(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall put_CompanyId(uint16_t) noexcept = 0;
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall put_Data(void*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(uint16_t, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisement
    {
        [[nodiscard]] auto Flags() const;
        auto Flags(Windows::Foundation::IReference<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags> const& value) const;
        [[nodiscard]] auto LocalName() const;
        auto LocalName(param::hstring const& value) const;
        [[nodiscard]] auto ServiceUuids() const;
        [[nodiscard]] auto ManufacturerData() const;
        [[nodiscard]] auto DataSections() const;
        auto GetManufacturerDataByCompanyId(uint16_t companyId) const;
        auto GetSectionsByType(uint8_t type) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisement<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementBytePattern
    {
        [[nodiscard]] auto DataType() const;
        auto DataType(uint8_t value) const;
        [[nodiscard]] auto Offset() const;
        auto Offset(int16_t value) const;
        [[nodiscard]] auto Data() const;
        auto Data(Windows::Storage::Streams::IBuffer const& value) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementBytePattern<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementBytePatternFactory
    {
        auto Create(uint8_t dataType, int16_t offset, Windows::Storage::Streams::IBuffer const& data) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementBytePatternFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementDataSection
    {
        [[nodiscard]] auto DataType() const;
        auto DataType(uint8_t value) const;
        [[nodiscard]] auto Data() const;
        auto Data(Windows::Storage::Streams::IBuffer const& value) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementDataSection<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementDataSectionFactory
    {
        auto Create(uint8_t dataType, Windows::Storage::Streams::IBuffer const& data) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementDataSectionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementDataTypesStatics
    {
        [[nodiscard]] auto Flags() const;
        [[nodiscard]] auto IncompleteService16BitUuids() const;
        [[nodiscard]] auto CompleteService16BitUuids() const;
        [[nodiscard]] auto IncompleteService32BitUuids() const;
        [[nodiscard]] auto CompleteService32BitUuids() const;
        [[nodiscard]] auto IncompleteService128BitUuids() const;
        [[nodiscard]] auto CompleteService128BitUuids() const;
        [[nodiscard]] auto ShortenedLocalName() const;
        [[nodiscard]] auto CompleteLocalName() const;
        [[nodiscard]] auto TxPowerLevel() const;
        [[nodiscard]] auto SlaveConnectionIntervalRange() const;
        [[nodiscard]] auto ServiceSolicitation16BitUuids() const;
        [[nodiscard]] auto ServiceSolicitation32BitUuids() const;
        [[nodiscard]] auto ServiceSolicitation128BitUuids() const;
        [[nodiscard]] auto ServiceData16BitUuids() const;
        [[nodiscard]] auto ServiceData32BitUuids() const;
        [[nodiscard]] auto ServiceData128BitUuids() const;
        [[nodiscard]] auto PublicTargetAddress() const;
        [[nodiscard]] auto RandomTargetAddress() const;
        [[nodiscard]] auto Appearance() const;
        [[nodiscard]] auto AdvertisingInterval() const;
        [[nodiscard]] auto ManufacturerSpecificData() const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementDataTypesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementFilter
    {
        [[nodiscard]] auto Advertisement() const;
        auto Advertisement(Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement const& value) const;
        [[nodiscard]] auto BytePatterns() const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementFilter<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisher
    {
        [[nodiscard]] auto Status() const;
        [[nodiscard]] auto Advertisement() const;
        auto Start() const;
        auto Stop() const;
        auto StatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs> const& handler) const;
        using StatusChanged_revoker = impl::event_revoker<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher, &impl::abi_t<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>::remove_StatusChanged>;
        StatusChanged_revoker StatusChanged(auto_revoke_t, Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs> const& handler) const;
        auto StatusChanged(winrt::event_token const& token) const noexcept;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisher<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisher2
    {
        [[nodiscard]] auto PreferredTransmitPowerLevelInDBm() const;
        auto PreferredTransmitPowerLevelInDBm(Windows::Foundation::IReference<int16_t> const& value) const;
        [[nodiscard]] auto UseExtendedAdvertisement() const;
        auto UseExtendedAdvertisement(bool value) const;
        [[nodiscard]] auto IsAnonymous() const;
        auto IsAnonymous(bool value) const;
        [[nodiscard]] auto IncludeTransmitPowerLevel() const;
        auto IncludeTransmitPowerLevel(bool value) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher2>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisher2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisherFactory
    {
        auto Create(Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement const& advertisement) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisherFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisherStatusChangedEventArgs
    {
        [[nodiscard]] auto Status() const;
        [[nodiscard]] auto Error() const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisherStatusChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2
    {
        [[nodiscard]] auto SelectedTransmitPowerLevelInDBm() const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementReceivedEventArgs
    {
        [[nodiscard]] auto RawSignalStrengthInDBm() const;
        [[nodiscard]] auto BluetoothAddress() const;
        [[nodiscard]] auto AdvertisementType() const;
        [[nodiscard]] auto Timestamp() const;
        [[nodiscard]] auto Advertisement() const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementReceivedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementReceivedEventArgs2
    {
        [[nodiscard]] auto BluetoothAddressType() const;
        [[nodiscard]] auto TransmitPowerLevelInDBm() const;
        [[nodiscard]] auto IsAnonymous() const;
        [[nodiscard]] auto IsConnectable() const;
        [[nodiscard]] auto IsScannable() const;
        [[nodiscard]] auto IsDirected() const;
        [[nodiscard]] auto IsScanResponse() const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs2>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementReceivedEventArgs2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementWatcher
    {
        [[nodiscard]] auto MinSamplingInterval() const;
        [[nodiscard]] auto MaxSamplingInterval() const;
        [[nodiscard]] auto MinOutOfRangeTimeout() const;
        [[nodiscard]] auto MaxOutOfRangeTimeout() const;
        [[nodiscard]] auto Status() const;
        [[nodiscard]] auto ScanningMode() const;
        auto ScanningMode(Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode const& value) const;
        [[nodiscard]] auto SignalStrengthFilter() const;
        auto SignalStrengthFilter(Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter const& value) const;
        [[nodiscard]] auto AdvertisementFilter() const;
        auto AdvertisementFilter(Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter const& value) const;
        auto Start() const;
        auto Stop() const;
        auto Received(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> const& handler) const;
        using Received_revoker = impl::event_revoker<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher, &impl::abi_t<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>::remove_Received>;
        Received_revoker Received(auto_revoke_t, Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> const& handler) const;
        auto Received(winrt::event_token const& token) const noexcept;
        auto Stopped(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs> const& handler) const;
        using Stopped_revoker = impl::event_revoker<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher, &impl::abi_t<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>::remove_Stopped>;
        Stopped_revoker Stopped(auto_revoke_t, Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs> const& handler) const;
        auto Stopped(winrt::event_token const& token) const noexcept;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementWatcher<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementWatcher2
    {
        [[nodiscard]] auto AllowExtendedAdvertisements() const;
        auto AllowExtendedAdvertisements(bool value) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher2>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementWatcher2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementWatcherFactory
    {
        auto Create(Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter const& advertisementFilter) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementWatcherFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementWatcherStoppedEventArgs
    {
        [[nodiscard]] auto Error() const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEAdvertisementWatcherStoppedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEManufacturerData
    {
        [[nodiscard]] auto CompanyId() const;
        auto CompanyId(uint16_t value) const;
        [[nodiscard]] auto Data() const;
        auto Data(Windows::Storage::Streams::IBuffer const& value) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEManufacturerData<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEManufacturerDataFactory
    {
        auto Create(uint16_t companyId, Windows::Storage::Streams::IBuffer const& data) const;
    };
    template <> struct consume<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Bluetooth_Advertisement_IBluetoothLEManufacturerDataFactory<D>;
    };
}
#endif
