
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif /*COM_NO_WINDOWS_H*/
#ifndef __windows2Eui2Ecore2Epreview2Ecommunications_h__
#define __windows2Eui2Ecore2Epreview2Ecommunications_h__
#ifndef __windows2Eui2Ecore2Epreview2Ecommunications_p_h__
#define __windows2Eui2Ecore2Epreview2Ecommunications_p_h__


#pragma once

//
// Deprecated attribute support
//

#pragma push_macro("DEPRECATED")
#undef DEPRECATED

#if !defined(DISABLE_WINRT_DEPRECATION)
#if defined(__cplusplus)
#if __cplusplus >= 201402
#define DEPRECATED(x) [[deprecated(x)]]
#define DEPRECATEDENUMERATOR(x) [[deprecated(x)]]
#elif defined(_MSC_VER)
#if _MSC_VER >= 1900
#define DEPRECATED(x) [[deprecated(x)]]
#define DEPRECATEDENUMERATOR(x) [[deprecated(x)]]
#else
#define DEPRECATED(x) __declspec(deprecated(x))
#define DEPRECATEDENUMERATOR(x)
#endif // _MSC_VER >= 1900
#else // Not Standard C++ or MSVC, ignore the construct.
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif  // C++ deprecation
#else // C - disable deprecation
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif
#else // Deprecation is disabled
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif  /* DEPRECATED */

// Disable Deprecation for this header, MIDL verifies that cross-type access is acceptable
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else
#pragma warning(push)
#pragma warning(disable: 4996)
#endif

// Ensure that the setting of the /ns_prefix command line switch is consistent for all headers.
// If you get an error from the compiler indicating "warning C4005: 'CHECK_NS_PREFIX_STATE': macro redefinition", this
// indicates that you have included two different headers with different settings for the /ns_prefix MIDL command line switch
#if !defined(DISABLE_NS_PREFIX_CHECKS)
#define CHECK_NS_PREFIX_STATE "always"
#endif // !defined(DISABLE_NS_PREFIX_CHECKS)


#pragma push_macro("MIDL_CONST_ID")
#undef MIDL_CONST_ID
#define MIDL_CONST_ID const __declspec(selectany)


//  API Contract Inclusion Definitions
#if !defined(SPECIFIC_API_CONTRACT_DEFINITIONS)
#if !defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)
#define WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0xa0000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#if !defined(WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION)
#define WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        interface IPreviewTeamCleanupRequestedEventArgs;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamCleanupRequestedEventArgs

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        interface IPreviewTeamCommandInvokedEventArgs;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamCommandInvokedEventArgs

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        interface IPreviewTeamDeviceCredentials;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamDeviceCredentials

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        interface IPreviewTeamEndMeetingRequestedEventArgs;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamEndMeetingRequestedEventArgs

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        interface IPreviewTeamJoinMeetingRequestedEventArgs;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamJoinMeetingRequestedEventArgs

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        interface IPreviewTeamView;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamView

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        interface IPreviewTeamView2;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2 ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamView2

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        interface IPreviewTeamViewStatics;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamViewStatics

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        class PreviewTeamView;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_USE
#define DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("acb338ef-9bc0-57fd-a2cf-3c391d977c9a"))
ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, IInspectable*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamView*>, IInspectable*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.UI.Core.Preview.Communications.PreviewTeamView, Object>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, IInspectable*> __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_t;
#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_USE */

#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        class PreviewTeamCleanupRequestedEventArgs;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("044f68a0-5ce8-57e9-950f-61d0859728eb"))
ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::PreviewTeamCleanupRequestedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamView*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamCleanupRequestedEventArgs*, ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamCleanupRequestedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.UI.Core.Preview.Communications.PreviewTeamView, Windows.UI.Core.Preview.Communications.PreviewTeamCleanupRequestedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::PreviewTeamCleanupRequestedEventArgs*> __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_USE */

#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        class PreviewTeamCommandInvokedEventArgs;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("3032cb23-b5fa-5b37-919a-854d3d31ba91"))
ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::PreviewTeamCommandInvokedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamView*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamCommandInvokedEventArgs*, ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamCommandInvokedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.UI.Core.Preview.Communications.PreviewTeamView, Windows.UI.Core.Preview.Communications.PreviewTeamCommandInvokedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::PreviewTeamCommandInvokedEventArgs*> __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_USE */

#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        class PreviewTeamEndMeetingRequestedEventArgs;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("2dcd39d5-81c9-5804-89f2-2274fb3f2fbc"))
ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::PreviewTeamEndMeetingRequestedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamView*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamEndMeetingRequestedEventArgs*, ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamEndMeetingRequestedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.UI.Core.Preview.Communications.PreviewTeamView, Windows.UI.Core.Preview.Communications.PreviewTeamEndMeetingRequestedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::PreviewTeamEndMeetingRequestedEventArgs*> __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_USE */

#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        class PreviewTeamJoinMeetingRequestedEventArgs;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("18e5fe9e-3e76-512b-beae-409eb0592ba3"))
ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::PreviewTeamJoinMeetingRequestedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamView*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamJoinMeetingRequestedEventArgs*, ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamJoinMeetingRequestedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.UI.Core.Preview.Communications.PreviewTeamView, Windows.UI.Core.Preview.Communications.PreviewTeamJoinMeetingRequestedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::UI::Core::Preview::Communications::PreviewTeamView*, ABI::Windows::UI::Core::Preview::Communications::PreviewTeamJoinMeetingRequestedEventArgs*> __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_USE */

#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Foundation {
            class Deferral;
        } /* Foundation */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IDeferral;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIDeferral ABI::Windows::Foundation::IDeferral

#endif // ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Foundation {
            typedef struct Rect Rect;
        } /* Foundation */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Foundation {
            class Uri;
        } /* Foundation */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IUriRuntimeClass;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIUriRuntimeClass ABI::Windows::Foundation::IUriRuntimeClass

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        typedef enum PreviewMeetingInfoDisplayKind : int PreviewMeetingInfoDisplayKind;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        typedef enum PreviewSystemState : int PreviewSystemState;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        typedef enum PreviewTeamEndMeetingKind : int PreviewTeamEndMeetingKind;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        typedef enum PreviewTeamViewCommand : int PreviewTeamViewCommand;
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.UI.Core.Preview.Communications.PreviewMeetingInfoDisplayKind
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        enum PreviewMeetingInfoDisplayKind : int
                        {
                            PreviewMeetingInfoDisplayKind_OrganizerAndTime = 0,
                            PreviewMeetingInfoDisplayKind_OrganizerTimeAndTitle = 1,
                        };
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Core.Preview.Communications.PreviewSystemState
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        enum PreviewSystemState : int
                        {
                            PreviewSystemState_Preparing = 0,
                            PreviewSystemState_Rebooting = 1,
                            PreviewSystemState_Error = 2,
                            PreviewSystemState_SessionPaused = 3,
                            PreviewSystemState_Ready = 4,
                        };
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Core.Preview.Communications.PreviewTeamEndMeetingKind
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        enum PreviewTeamEndMeetingKind : int
                        {
                            PreviewTeamEndMeetingKind_ShowDefaultView = 0,
                            PreviewTeamEndMeetingKind_CloseView = 1,
                        };
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Core.Preview.Communications.PreviewTeamViewCommand
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        enum PreviewTeamViewCommand : int
                        {
                            PreviewTeamViewCommand_ToggleCallControl = 0,
                            PreviewTeamViewCommand_ShowPeople = 1,
                            PreviewTeamViewCommand_ShowMessaging = 2,
                            PreviewTeamViewCommand_ShowContent = 3,
                            PreviewTeamViewCommand_ToggleMicrophone = 4,
                            PreviewTeamViewCommand_ToggleCamera = 5,
                            PreviewTeamViewCommand_ShowCalendar = 6,
                            PreviewTeamViewCommand_ToggleScreenSharing = 7,
                            PreviewTeamViewCommand_ToggleFullScreen = 8,
                        };
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamCleanupRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamCleanupRequestedEventArgs
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamCleanupRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamCleanupRequestedEventArgs";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        MIDL_INTERFACE("f0190610-05af-4250-b96a-a74edef77a0d")
                        IPreviewTeamCleanupRequestedEventArgs : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                                ABI::Windows::Foundation::IDeferral** result
                                ) = 0;
                        };

                        extern MIDL_CONST_ID IID& IID_IPreviewTeamCleanupRequestedEventArgs = _uuidof(IPreviewTeamCleanupRequestedEventArgs);
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamCommandInvokedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamCommandInvokedEventArgs
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamCommandInvokedEventArgs[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamCommandInvokedEventArgs";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        MIDL_INTERFACE("661f4165-fe71-44af-9568-6cc7cf29cd4c")
                        IPreviewTeamCommandInvokedEventArgs : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE get_Command(
                                ABI::Windows::UI::Core::Preview::Communications::PreviewTeamViewCommand* value
                                ) = 0;
                        };

                        extern MIDL_CONST_ID IID& IID_IPreviewTeamCommandInvokedEventArgs = _uuidof(IPreviewTeamCommandInvokedEventArgs);
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamDeviceCredentials
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamDeviceCredentials
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamDeviceCredentials[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamDeviceCredentials";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        MIDL_INTERFACE("8959c9b9-02fc-4d1d-8921-d61e7766cb89")
                        IPreviewTeamDeviceCredentials : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE get_UserPrincipalName(
                                HSTRING* value
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE get_DomainUserName(
                                HSTRING* value
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE get_Password(
                                HSTRING* value
                                ) = 0;
                        };

                        extern MIDL_CONST_ID IID& IID_IPreviewTeamDeviceCredentials = _uuidof(IPreviewTeamDeviceCredentials);
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamEndMeetingRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamEndMeetingRequestedEventArgs
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamEndMeetingRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamEndMeetingRequestedEventArgs";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        MIDL_INTERFACE("10b149e1-b6f1-4ca7-b4ce-2c66a4a64699")
                        IPreviewTeamEndMeetingRequestedEventArgs : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                                ABI::Windows::Foundation::IDeferral** result
                                ) = 0;
                        };

                        extern MIDL_CONST_ID IID& IID_IPreviewTeamEndMeetingRequestedEventArgs = _uuidof(IPreviewTeamEndMeetingRequestedEventArgs);
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamJoinMeetingRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamJoinMeetingRequestedEventArgs
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamJoinMeetingRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamJoinMeetingRequestedEventArgs";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        MIDL_INTERFACE("421e6adb-98d7-41ae-ba49-6caf559b8f5a")
                        IPreviewTeamJoinMeetingRequestedEventArgs : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                                ABI::Windows::Foundation::IDeferral** result
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE get_MeetingUri(
                                ABI::Windows::Foundation::IUriRuntimeClass** value
                                ) = 0;
                        };

                        extern MIDL_CONST_ID IID& IID_IPreviewTeamJoinMeetingRequestedEventArgs = _uuidof(IPreviewTeamJoinMeetingRequestedEventArgs);
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamView
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamView
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamView[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamView";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        MIDL_INTERFACE("6f616677-02ae-49a0-aa50-862d078cf9b1")
                        IPreviewTeamView : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE SetTitle(
                                HSTRING title
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE EnterFullScreen(void) = 0;
                            virtual HRESULT STDMETHODCALLTYPE LeaveFullScreen(void) = 0;
                            virtual HRESULT STDMETHODCALLTYPE RequestForeground(void) = 0;
                            virtual HRESULT STDMETHODCALLTYPE StartSharingScreen(void) = 0;
                            virtual HRESULT STDMETHODCALLTYPE StopSharingScreen(void) = 0;
                            virtual HRESULT STDMETHODCALLTYPE NotifyMeetingEnded(
                                ABI::Windows::UI::Core::Preview::Communications::PreviewTeamEndMeetingKind kind
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE JoinMeetingWithUri(
                                ABI::Windows::Foundation::IUriRuntimeClass* meetingUri
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE get_MeetingUri(
                                ABI::Windows::Foundation::IUriRuntimeClass** value
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE get_SharingScreenBounds(
                                ABI::Windows::Foundation::Rect* value
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE get_IsScreenSharing(
                                boolean* value
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE get_IsFullScreen(
                                boolean* value
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE get_SystemState(
                                ABI::Windows::UI::Core::Preview::Communications::PreviewSystemState* value
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE get_MeetingInfoDisplayType(
                                ABI::Windows::UI::Core::Preview::Communications::PreviewMeetingInfoDisplayKind* value
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE add_JoinMeetingRequested(
                                __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs* handler,
                                EventRegistrationToken* token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE remove_JoinMeetingRequested(
                                EventRegistrationToken token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE add_EndMeetingRequested(
                                __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs* handler,
                                EventRegistrationToken* token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE remove_EndMeetingRequested(
                                EventRegistrationToken token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE add_CleanupRequested(
                                __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs* handler,
                                EventRegistrationToken* token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE remove_CleanupRequested(
                                EventRegistrationToken token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE add_SharingScreenBoundsChanged(
                                __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* handler,
                                EventRegistrationToken* token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE remove_SharingScreenBoundsChanged(
                                EventRegistrationToken token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE add_IsScreenSharingChanged(
                                __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* handler,
                                EventRegistrationToken* token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE remove_IsScreenSharingChanged(
                                EventRegistrationToken token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE add_IsFullScreenChanged(
                                __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* handler,
                                EventRegistrationToken* token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE remove_IsFullScreenChanged(
                                EventRegistrationToken token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE add_CommandInvoked(
                                __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs* handler,
                                EventRegistrationToken* token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE remove_CommandInvoked(
                                EventRegistrationToken token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE add_SystemStateChanged(
                                __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* handler,
                                EventRegistrationToken* token
                                ) = 0;
                            virtual HRESULT STDMETHODCALLTYPE remove_SystemStateChanged(
                                EventRegistrationToken token
                                ) = 0;
                        };

                        extern MIDL_CONST_ID IID& IID_IPreviewTeamView = _uuidof(IPreviewTeamView);
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamView2
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamView
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamView2[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamView2";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        MIDL_INTERFACE("bd44b2a2-0d77-416d-a370-9ea5ece46229")
                        IPreviewTeamView2 : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE SetButtonLabel(
                                HSTRING label
                                ) = 0;
                        };

                        extern MIDL_CONST_ID IID& IID_IPreviewTeamView2 = _uuidof(IPreviewTeamView2);
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamViewStatics
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamView
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamViewStatics[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamViewStatics";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Core {
                namespace Preview {
                    namespace Communications {
                        MIDL_INTERFACE("fe241233-d49c-49ee-b798-ec31d9543938")
                        IPreviewTeamViewStatics : public IInspectable
                        {
                        public:
                            virtual HRESULT STDMETHODCALLTYPE GetForCurrentView(
                                ABI::Windows::UI::Core::Preview::Communications::IPreviewTeamView** result
                                ) = 0;
                        };

                        extern MIDL_CONST_ID IID& IID_IPreviewTeamViewStatics = _uuidof(IPreviewTeamViewStatics);
                    } /* Communications */
                } /* Preview */
            } /* Core */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamCleanupRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamCleanupRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamCleanupRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamCleanupRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamCleanupRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamCleanupRequestedEventArgs";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamCommandInvokedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamCommandInvokedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamCommandInvokedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamCommandInvokedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamCommandInvokedEventArgs[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamCommandInvokedEventArgs";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamDeviceCredentials
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamDeviceCredentials ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamDeviceCredentials_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamDeviceCredentials_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamDeviceCredentials[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamDeviceCredentials";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamEndMeetingRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamEndMeetingRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamEndMeetingRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamEndMeetingRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamEndMeetingRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamEndMeetingRequestedEventArgs";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamJoinMeetingRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamJoinMeetingRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamJoinMeetingRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamJoinMeetingRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamJoinMeetingRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamJoinMeetingRequestedEventArgs";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamView
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Core.Preview.Communications.IPreviewTeamViewStatics interface starting with version 1.0 of the Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamView ** Default Interface **
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamView2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamView_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamView_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamView[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamView";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs;

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs;

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials;

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs;

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs;

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView;

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2 __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2;

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics;

#endif // ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable;

typedef struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectableVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* This,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* sender,
        IInspectable* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectableVtbl;

interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectableVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable_INTERFACE_DEFINED__
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs* This,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* sender,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs* This,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* sender,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs* This,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* sender,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs* This,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* sender,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#ifndef ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIDeferral __x_ABI_CWindows_CFoundation_CIDeferral;

#endif // ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__

typedef struct __x_ABI_CWindows_CFoundation_CRect __x_ABI_CWindows_CFoundation_CRect;

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__

typedef enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewMeetingInfoDisplayKind __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewMeetingInfoDisplayKind;

typedef enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewSystemState __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewSystemState;

typedef enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewTeamEndMeetingKind __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewTeamEndMeetingKind;

typedef enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewTeamViewCommand __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewTeamViewCommand;

/*
 *
 * Struct Windows.UI.Core.Preview.Communications.PreviewMeetingInfoDisplayKind
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewMeetingInfoDisplayKind
{
    PreviewMeetingInfoDisplayKind_OrganizerAndTime = 0,
    PreviewMeetingInfoDisplayKind_OrganizerTimeAndTitle = 1,
};
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Core.Preview.Communications.PreviewSystemState
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewSystemState
{
    PreviewSystemState_Preparing = 0,
    PreviewSystemState_Rebooting = 1,
    PreviewSystemState_Error = 2,
    PreviewSystemState_SessionPaused = 3,
    PreviewSystemState_Ready = 4,
};
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Core.Preview.Communications.PreviewTeamEndMeetingKind
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewTeamEndMeetingKind
{
    PreviewTeamEndMeetingKind_ShowDefaultView = 0,
    PreviewTeamEndMeetingKind_CloseView = 1,
};
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Core.Preview.Communications.PreviewTeamViewCommand
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewTeamViewCommand
{
    PreviewTeamViewCommand_ToggleCallControl = 0,
    PreviewTeamViewCommand_ShowPeople = 1,
    PreviewTeamViewCommand_ShowMessaging = 2,
    PreviewTeamViewCommand_ShowContent = 3,
    PreviewTeamViewCommand_ToggleMicrophone = 4,
    PreviewTeamViewCommand_ToggleCamera = 5,
    PreviewTeamViewCommand_ShowCalendar = 6,
    PreviewTeamViewCommand_ToggleScreenSharing = 7,
    PreviewTeamViewCommand_ToggleFullScreen = 8,
};
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamCleanupRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamCleanupRequestedEventArgs
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamCleanupRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamCleanupRequestedEventArgs";
typedef struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgsVtbl;

interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCleanupRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamCommandInvokedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamCommandInvokedEventArgs
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamCommandInvokedEventArgs[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamCommandInvokedEventArgs";
typedef struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Command)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs* This,
        enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewTeamViewCommand* value);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgsVtbl;

interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_get_Command(This, value) \
    ((This)->lpVtbl->get_Command(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamCommandInvokedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamDeviceCredentials
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamDeviceCredentials
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamDeviceCredentials[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamDeviceCredentials";
typedef struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentialsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_UserPrincipalName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_DomainUserName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Password)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentialsVtbl;

interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentialsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_get_UserPrincipalName(This, value) \
    ((This)->lpVtbl->get_UserPrincipalName(This, value))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_get_DomainUserName(This, value) \
    ((This)->lpVtbl->get_DomainUserName(This, value))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_get_Password(This, value) \
    ((This)->lpVtbl->get_Password(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamDeviceCredentials_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamEndMeetingRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamEndMeetingRequestedEventArgs
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamEndMeetingRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamEndMeetingRequestedEventArgs";
typedef struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgsVtbl;

interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamEndMeetingRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamJoinMeetingRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamJoinMeetingRequestedEventArgs
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamJoinMeetingRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamJoinMeetingRequestedEventArgs";
typedef struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);
    HRESULT (STDMETHODCALLTYPE* get_MeetingUri)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgsVtbl;

interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_get_MeetingUri(This, value) \
    ((This)->lpVtbl->get_MeetingUri(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamJoinMeetingRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamView
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamView
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamView[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamView";
typedef struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* SetTitle)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        HSTRING title);
    HRESULT (STDMETHODCALLTYPE* EnterFullScreen)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This);
    HRESULT (STDMETHODCALLTYPE* LeaveFullScreen)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This);
    HRESULT (STDMETHODCALLTYPE* RequestForeground)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This);
    HRESULT (STDMETHODCALLTYPE* StartSharingScreen)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This);
    HRESULT (STDMETHODCALLTYPE* StopSharingScreen)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This);
    HRESULT (STDMETHODCALLTYPE* NotifyMeetingEnded)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewTeamEndMeetingKind kind);
    HRESULT (STDMETHODCALLTYPE* JoinMeetingWithUri)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* meetingUri);
    HRESULT (STDMETHODCALLTYPE* get_MeetingUri)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* get_SharingScreenBounds)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        struct __x_ABI_CWindows_CFoundation_CRect* value);
    HRESULT (STDMETHODCALLTYPE* get_IsScreenSharing)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsFullScreen)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_SystemState)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewSystemState* value);
    HRESULT (STDMETHODCALLTYPE* get_MeetingInfoDisplayType)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        enum __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CPreviewMeetingInfoDisplayKind* value);
    HRESULT (STDMETHODCALLTYPE* add_JoinMeetingRequested)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamJoinMeetingRequestedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_JoinMeetingRequested)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_EndMeetingRequested)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamEndMeetingRequestedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_EndMeetingRequested)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_CleanupRequested)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCleanupRequestedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_CleanupRequested)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_SharingScreenBoundsChanged)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_SharingScreenBoundsChanged)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_IsScreenSharingChanged)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_IsScreenSharingChanged)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_IsFullScreenChanged)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_IsFullScreenChanged)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_CommandInvoked)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamCommandInvokedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_CommandInvoked)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_SystemStateChanged)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        __FITypedEventHandler_2_Windows__CUI__CCore__CPreview__CCommunications__CPreviewTeamView_IInspectable* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_SystemStateChanged)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView* This,
        EventRegistrationToken token);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewVtbl;

interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_SetTitle(This, title) \
    ((This)->lpVtbl->SetTitle(This, title))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_EnterFullScreen(This) \
    ((This)->lpVtbl->EnterFullScreen(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_LeaveFullScreen(This) \
    ((This)->lpVtbl->LeaveFullScreen(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_RequestForeground(This) \
    ((This)->lpVtbl->RequestForeground(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_StartSharingScreen(This) \
    ((This)->lpVtbl->StartSharingScreen(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_StopSharingScreen(This) \
    ((This)->lpVtbl->StopSharingScreen(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_NotifyMeetingEnded(This, kind) \
    ((This)->lpVtbl->NotifyMeetingEnded(This, kind))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_JoinMeetingWithUri(This, meetingUri) \
    ((This)->lpVtbl->JoinMeetingWithUri(This, meetingUri))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_get_MeetingUri(This, value) \
    ((This)->lpVtbl->get_MeetingUri(This, value))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_get_SharingScreenBounds(This, value) \
    ((This)->lpVtbl->get_SharingScreenBounds(This, value))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_get_IsScreenSharing(This, value) \
    ((This)->lpVtbl->get_IsScreenSharing(This, value))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_get_IsFullScreen(This, value) \
    ((This)->lpVtbl->get_IsFullScreen(This, value))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_get_SystemState(This, value) \
    ((This)->lpVtbl->get_SystemState(This, value))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_get_MeetingInfoDisplayType(This, value) \
    ((This)->lpVtbl->get_MeetingInfoDisplayType(This, value))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_add_JoinMeetingRequested(This, handler, token) \
    ((This)->lpVtbl->add_JoinMeetingRequested(This, handler, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_remove_JoinMeetingRequested(This, token) \
    ((This)->lpVtbl->remove_JoinMeetingRequested(This, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_add_EndMeetingRequested(This, handler, token) \
    ((This)->lpVtbl->add_EndMeetingRequested(This, handler, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_remove_EndMeetingRequested(This, token) \
    ((This)->lpVtbl->remove_EndMeetingRequested(This, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_add_CleanupRequested(This, handler, token) \
    ((This)->lpVtbl->add_CleanupRequested(This, handler, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_remove_CleanupRequested(This, token) \
    ((This)->lpVtbl->remove_CleanupRequested(This, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_add_SharingScreenBoundsChanged(This, handler, token) \
    ((This)->lpVtbl->add_SharingScreenBoundsChanged(This, handler, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_remove_SharingScreenBoundsChanged(This, token) \
    ((This)->lpVtbl->remove_SharingScreenBoundsChanged(This, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_add_IsScreenSharingChanged(This, handler, token) \
    ((This)->lpVtbl->add_IsScreenSharingChanged(This, handler, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_remove_IsScreenSharingChanged(This, token) \
    ((This)->lpVtbl->remove_IsScreenSharingChanged(This, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_add_IsFullScreenChanged(This, handler, token) \
    ((This)->lpVtbl->add_IsFullScreenChanged(This, handler, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_remove_IsFullScreenChanged(This, token) \
    ((This)->lpVtbl->remove_IsFullScreenChanged(This, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_add_CommandInvoked(This, handler, token) \
    ((This)->lpVtbl->add_CommandInvoked(This, handler, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_remove_CommandInvoked(This, token) \
    ((This)->lpVtbl->remove_CommandInvoked(This, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_add_SystemStateChanged(This, handler, token) \
    ((This)->lpVtbl->add_SystemStateChanged(This, handler, token))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_remove_SystemStateChanged(This, token) \
    ((This)->lpVtbl->remove_SystemStateChanged(This, token))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamView2
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamView
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamView2[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamView2";
typedef struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* SetButtonLabel)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2* This,
        HSTRING label);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2Vtbl;

interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_SetButtonLabel(This, label) \
    ((This)->lpVtbl->SetButtonLabel(This, label))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView2_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Core.Preview.Communications.IPreviewTeamViewStatics
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Core.Preview.Communications.PreviewTeamView
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Core_Preview_Communications_IPreviewTeamViewStatics[] = L"Windows.UI.Core.Preview.Communications.IPreviewTeamViewStatics";
typedef struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetForCurrentView)(__x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics* This,
        __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamView** result);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStaticsVtbl;

interface __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_GetForCurrentView(This, result) \
    ((This)->lpVtbl->GetForCurrentView(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CCore_CPreview_CCommunications_CIPreviewTeamViewStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamCleanupRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamCleanupRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamCleanupRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamCleanupRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamCleanupRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamCleanupRequestedEventArgs";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamCommandInvokedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamCommandInvokedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamCommandInvokedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamCommandInvokedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamCommandInvokedEventArgs[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamCommandInvokedEventArgs";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamDeviceCredentials
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamDeviceCredentials ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamDeviceCredentials_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamDeviceCredentials_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamDeviceCredentials[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamDeviceCredentials";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamEndMeetingRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamEndMeetingRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamEndMeetingRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamEndMeetingRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamEndMeetingRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamEndMeetingRequestedEventArgs";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamJoinMeetingRequestedEventArgs
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamJoinMeetingRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamJoinMeetingRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamJoinMeetingRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamJoinMeetingRequestedEventArgs[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamJoinMeetingRequestedEventArgs";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Core.Preview.Communications.PreviewTeamView
 *
 * Introduced to Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Core.Preview.Communications.IPreviewTeamViewStatics interface starting with version 1.0 of the Windows.UI.Core.Preview.Communications.PreviewCommunicationsContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamView ** Default Interface **
 *    Windows.UI.Core.Preview.Communications.IPreviewTeamView2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamView_DEFINED
#define RUNTIMECLASS_Windows_UI_Core_Preview_Communications_PreviewTeamView_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Core_Preview_Communications_PreviewTeamView[] = L"Windows.UI.Core.Preview.Communications.PreviewTeamView";
#endif
#endif // WINDOWS_UI_CORE_PREVIEW_COMMUNICATIONS_PREVIEWCOMMUNICATIONSCONTRACT_VERSION >= 0x10000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Eui2Ecore2Epreview2Ecommunications_p_h__

#endif // __windows2Eui2Ecore2Epreview2Ecommunications_h__
