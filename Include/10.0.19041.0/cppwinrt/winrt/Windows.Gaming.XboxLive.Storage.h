// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_Gaming_XboxLive_Storage_H
#define WINRT_Windows_Gaming_XboxLive_Storage_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.190620.2"), "Mismatched C++/WinRT headers.");
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.Foundation.Collections.2.h"
#include "winrt/impl/Windows.Storage.Streams.2.h"
#include "winrt/impl/Windows.System.2.h"
#include "winrt/impl/Windows.Gaming.XboxLive.Storage.2.h"
namespace winrt::impl
{
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobGetResult<D>::Status() const
    {
        Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult)->get_Status(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobGetResult<D>::Value() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult)->get_Value(&value));
        return Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::Streams::IBuffer>{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfo<D>::Name() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfo<D>::Size() const
    {
        uint32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo)->get_Size(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoGetResult<D>::Status() const
    {
        Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult)->get_Status(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoGetResult<D>::Value() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult)->get_Value(&value));
        return Windows::Foundation::Collections::IVectorView<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoQuery<D>::GetBlobInfoAsync() const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery)->GetBlobInfoAsync(&operation));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoQuery<D>::GetBlobInfoAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery)->GetBlobInfoWithIndexAndMaxAsync(startIndex, maxNumberOfItems, &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoQuery<D>::GetItemCountAsync() const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery)->GetItemCountAsync(&operation));
        return Windows::Foundation::IAsyncOperation<uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::Name() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainer)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::Provider() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainer)->get_Provider(&value));
        return Windows::Gaming::XboxLive::Storage::GameSaveProvider{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::SubmitUpdatesAsync(param::async_map_view<hstring, Windows::Storage::Streams::IBuffer> const& blobsToWrite, param::async_iterable<hstring> const& blobsToDelete, param::hstring const& displayName) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainer)->SubmitUpdatesAsync(*(void**)(&blobsToWrite), *(void**)(&blobsToDelete), *(void**)(&displayName), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::ReadAsync(param::async_map_view<hstring, Windows::Storage::Streams::IBuffer> const& blobsToRead) const
    {
        void* action{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainer)->ReadAsync(*(void**)(&blobsToRead), &action));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>{ action, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::GetAsync(param::async_iterable<hstring> const& blobsToRead) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainer)->GetAsync(*(void**)(&blobsToRead), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveBlobGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::SubmitPropertySetUpdatesAsync(Windows::Foundation::Collections::IPropertySet const& blobsToWrite, param::async_iterable<hstring> const& blobsToDelete, param::hstring const& displayName) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainer)->SubmitPropertySetUpdatesAsync(*(void**)(&blobsToWrite), *(void**)(&blobsToDelete), *(void**)(&displayName), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::CreateBlobInfoQuery(param::hstring const& blobNamePrefix) const
    {
        void* query{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainer)->CreateBlobInfoQuery(*(void**)(&blobNamePrefix), &query));
        return Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery{ query, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::Name() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::TotalSize() const
    {
        uint64_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_TotalSize(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::LastModifiedTime() const
    {
        Windows::Foundation::DateTime value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_LastModifiedTime(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::NeedsSync() const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_NeedsSync(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoGetResult<D>::Status() const
    {
        Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult)->get_Status(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoGetResult<D>::Value() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult)->get_Value(&value));
        return Windows::Foundation::Collections::IVectorView<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoQuery<D>::GetContainerInfoAsync() const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery)->GetContainerInfoAsync(&operation));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoQuery<D>::GetContainerInfoAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery)->GetContainerInfoWithIndexAndMaxAsync(startIndex, maxNumberOfItems, &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoQuery<D>::GetItemCountAsync() const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery)->GetItemCountAsync(&operation));
        return Windows::Foundation::IAsyncOperation<uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveOperationResult<D>::Status() const
    {
        Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult)->get_Status(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::User() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProvider)->get_User(&value));
        return Windows::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::CreateContainer(param::hstring const& name) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProvider)->CreateContainer(*(void**)(&name), &result));
        return Windows::Gaming::XboxLive::Storage::GameSaveContainer{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::DeleteContainerAsync(param::hstring const& name) const
    {
        void* action{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProvider)->DeleteContainerAsync(*(void**)(&name), &action));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>{ action, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::CreateContainerInfoQuery() const
    {
        void* query{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProvider)->CreateContainerInfoQuery(&query));
        return Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery{ query, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::CreateContainerInfoQuery(param::hstring const& containerNamePrefix) const
    {
        void* query{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProvider)->CreateContainerInfoQueryWithName(*(void**)(&containerNamePrefix), &query));
        return Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery{ query, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::GetRemainingBytesInQuotaAsync() const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProvider)->GetRemainingBytesInQuotaAsync(&operation));
        return Windows::Foundation::IAsyncOperation<int64_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::ContainersChangedSinceLastSync() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProvider)->get_ContainersChangedSinceLastSync(&value));
        return Windows::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderGetResult<D>::Status() const
    {
        Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult)->get_Status(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderGetResult<D>::Value() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult)->get_Value(&value));
        return Windows::Gaming::XboxLive::Storage::GameSaveProvider{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderStatics<D>::GetForUserAsync(Windows::System::User const& user, param::hstring const& serviceConfigId) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics)->GetForUserAsync(*(void**)(&user), *(void**)(&serviceConfigId), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveProviderGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderStatics<D>::GetSyncOnDemandForUserAsync(Windows::System::User const& user, param::hstring const& serviceConfigId) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics)->GetSyncOnDemandForUserAsync(*(void**)(&user), *(void**)(&serviceConfigId), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveProviderGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::Streams::IBuffer>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::Collections::IVectorView<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfo>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery>
    {
        int32_t __stdcall GetBlobInfoAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>>(this->shim().GetBlobInfoAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBlobInfoWithIndexAndMaxAsync(uint32_t startIndex, uint32_t maxNumberOfItems, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>>(this->shim().GetBlobInfoAsync(startIndex, maxNumberOfItems));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemCountAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<uint32_t>>(this->shim().GetItemCountAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveContainer> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveContainer>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Provider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveProvider>(this->shim().Provider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SubmitUpdatesAsync(void* blobsToWrite, void* blobsToDelete, void* displayName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>>(this->shim().SubmitUpdatesAsync(*reinterpret_cast<Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::Streams::IBuffer> const*>(&blobsToWrite), *reinterpret_cast<Windows::Foundation::Collections::IIterable<hstring> const*>(&blobsToDelete), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReadAsync(void* blobsToRead, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>>(this->shim().ReadAsync(*reinterpret_cast<Windows::Foundation::Collections::IMapView<hstring, Windows::Storage::Streams::IBuffer> const*>(&blobsToRead)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAsync(void* blobsToRead, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveBlobGetResult>>(this->shim().GetAsync(*reinterpret_cast<Windows::Foundation::Collections::IIterable<hstring> const*>(&blobsToRead)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SubmitPropertySetUpdatesAsync(void* blobsToWrite, void* blobsToDelete, void* displayName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>>(this->shim().SubmitPropertySetUpdatesAsync(*reinterpret_cast<Windows::Foundation::Collections::IPropertySet const*>(&blobsToWrite), *reinterpret_cast<Windows::Foundation::Collections::IIterable<hstring> const*>(&blobsToDelete), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBlobInfoQuery(void* blobNamePrefix, void** query) noexcept final try
        {
            clear_abi(query);
            typename D::abi_guard guard(this->shim());
            *query = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery>(this->shim().CreateBlobInfoQuery(*reinterpret_cast<hstring const*>(&blobNamePrefix)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalSize(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LastModifiedTime(int64_t* value) noexcept final try
        {
            zero_abi<Windows::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::DateTime>(this->shim().LastModifiedTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeedsSync(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().NeedsSync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::Collections::IVectorView<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfo>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery>
    {
        int32_t __stdcall GetContainerInfoAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>>(this->shim().GetContainerInfoAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetContainerInfoWithIndexAndMaxAsync(uint32_t startIndex, uint32_t maxNumberOfItems, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>>(this->shim().GetContainerInfoAsync(startIndex, maxNumberOfItems));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemCountAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<uint32_t>>(this->shim().GetItemCountAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveProvider> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveProvider>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateContainer(void* name, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveContainer>(this->shim().CreateContainer(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteContainerAsync(void* name, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveOperationResult>>(this->shim().DeleteContainerAsync(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateContainerInfoQuery(void** query) noexcept final try
        {
            clear_abi(query);
            typename D::abi_guard guard(this->shim());
            *query = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery>(this->shim().CreateContainerInfoQuery());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateContainerInfoQueryWithName(void* containerNamePrefix, void** query) noexcept final try
        {
            clear_abi(query);
            typename D::abi_guard guard(this->shim());
            *query = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery>(this->shim().CreateContainerInfoQuery(*reinterpret_cast<hstring const*>(&containerNamePrefix)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRemainingBytesInQuotaAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<int64_t>>(this->shim().GetRemainingBytesInQuotaAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContainersChangedSinceLastSync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::Collections::IVectorView<hstring>>(this->shim().ContainersChangedSinceLastSync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Gaming::XboxLive::Storage::GameSaveProvider>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics> : produce_base<D, Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics>
    {
        int32_t __stdcall GetForUserAsync(void* user, void* serviceConfigId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveProviderGetResult>>(this->shim().GetForUserAsync(*reinterpret_cast<Windows::System::User const*>(&user), *reinterpret_cast<hstring const*>(&serviceConfigId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSyncOnDemandForUserAsync(void* user, void* serviceConfigId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Gaming::XboxLive::Storage::GameSaveProviderGetResult>>(this->shim().GetSyncOnDemandForUserAsync(*reinterpret_cast<Windows::System::User const*>(&user), *reinterpret_cast<hstring const*>(&serviceConfigId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
namespace winrt::Windows::Gaming::XboxLive::Storage
{
    inline auto GameSaveProvider::GetForUserAsync(Windows::System::User const& user, param::hstring const& serviceConfigId)
    {
        return impl::call_factory<GameSaveProvider, Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics>([&](auto&& f) { return f.GetForUserAsync(user, serviceConfigId); });
    }
    inline auto GameSaveProvider::GetSyncOnDemandForUserAsync(Windows::System::User const& user, param::hstring const& serviceConfigId)
    {
        return impl::call_factory<GameSaveProvider, Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics>([&](auto&& f) { return f.GetSyncOnDemandForUserAsync(user, serviceConfigId); });
    }
}
namespace std
{
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveBlobGetResult> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfo> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveContainer> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveContainer> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfo> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveOperationResult> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveProvider> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveProvider> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveProviderGetResult> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::IGameSaveProviderStatics> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveBlobGetResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveBlobGetResult> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveBlobInfo> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveBlobInfo> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveContainer> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveContainer> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveContainerInfo> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveContainerInfo> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveOperationResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveOperationResult> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveProvider> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveProvider> {};
    template<> struct hash<winrt::Windows::Gaming::XboxLive::Storage::GameSaveProviderGetResult> : winrt::impl::hash_base<winrt::Windows::Gaming::XboxLive::Storage::GameSaveProviderGetResult> {};
}
#endif
