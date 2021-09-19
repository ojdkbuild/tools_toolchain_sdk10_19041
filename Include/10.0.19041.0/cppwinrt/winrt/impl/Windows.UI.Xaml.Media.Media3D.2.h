// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_UI_Xaml_Media_Media3D_2_H
#define WINRT_Windows_UI_Xaml_Media_Media3D_2_H
#include "winrt/impl/Windows.UI.Xaml.1.h"
#include "winrt/impl/Windows.UI.Xaml.Media.Media3D.1.h"
namespace winrt::Windows::UI::Xaml::Media::Media3D
{
    struct Matrix3D
    {
        double M11;
        double M12;
        double M13;
        double M14;
        double M21;
        double M22;
        double M23;
        double M24;
        double M31;
        double M32;
        double M33;
        double M34;
        double OffsetX;
        double OffsetY;
        double OffsetZ;
        double M44;
    };
    inline bool operator==(Matrix3D const& left, Matrix3D const& right) noexcept
    {
        return left.M11 == right.M11 && left.M12 == right.M12 && left.M13 == right.M13 && left.M14 == right.M14 && left.M21 == right.M21 && left.M22 == right.M22 && left.M23 == right.M23 && left.M24 == right.M24 && left.M31 == right.M31 && left.M32 == right.M32 && left.M33 == right.M33 && left.M34 == right.M34 && left.OffsetX == right.OffsetX && left.OffsetY == right.OffsetY && left.OffsetZ == right.OffsetZ && left.M44 == right.M44;
    }
    inline bool operator!=(Matrix3D const& left, Matrix3D const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) CompositeTransform3D : Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D,
        impl::base<CompositeTransform3D, Windows::UI::Xaml::Media::Media3D::Transform3D, Windows::UI::Xaml::DependencyObject>,
        impl::require<CompositeTransform3D, Windows::UI::Xaml::Media::Media3D::ITransform3D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
    {
        CompositeTransform3D(std::nullptr_t) noexcept {}
        CompositeTransform3D(void* ptr, take_ownership_from_abi_t) noexcept : Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D(ptr, take_ownership_from_abi) {}
        CompositeTransform3D();
        [[nodiscard]] static auto CenterXProperty();
        [[nodiscard]] static auto CenterYProperty();
        [[nodiscard]] static auto CenterZProperty();
        [[nodiscard]] static auto RotationXProperty();
        [[nodiscard]] static auto RotationYProperty();
        [[nodiscard]] static auto RotationZProperty();
        [[nodiscard]] static auto ScaleXProperty();
        [[nodiscard]] static auto ScaleYProperty();
        [[nodiscard]] static auto ScaleZProperty();
        [[nodiscard]] static auto TranslateXProperty();
        [[nodiscard]] static auto TranslateYProperty();
        [[nodiscard]] static auto TranslateZProperty();
    };
    struct __declspec(empty_bases) Matrix3DHelper : Windows::UI::Xaml::Media::Media3D::IMatrix3DHelper
    {
        Matrix3DHelper(std::nullptr_t) noexcept {}
        Matrix3DHelper(void* ptr, take_ownership_from_abi_t) noexcept : Windows::UI::Xaml::Media::Media3D::IMatrix3DHelper(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Identity();
        static auto Multiply(Windows::UI::Xaml::Media::Media3D::Matrix3D const& matrix1, Windows::UI::Xaml::Media::Media3D::Matrix3D const& matrix2);
        static auto FromElements(double m11, double m12, double m13, double m14, double m21, double m22, double m23, double m24, double m31, double m32, double m33, double m34, double offsetX, double offsetY, double offsetZ, double m44);
        static auto GetHasInverse(Windows::UI::Xaml::Media::Media3D::Matrix3D const& target);
        static auto GetIsIdentity(Windows::UI::Xaml::Media::Media3D::Matrix3D const& target);
        static auto Invert(Windows::UI::Xaml::Media::Media3D::Matrix3D const& target);
    };
    struct __declspec(empty_bases) PerspectiveTransform3D : Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D,
        impl::base<PerspectiveTransform3D, Windows::UI::Xaml::Media::Media3D::Transform3D, Windows::UI::Xaml::DependencyObject>,
        impl::require<PerspectiveTransform3D, Windows::UI::Xaml::Media::Media3D::ITransform3D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
    {
        PerspectiveTransform3D(std::nullptr_t) noexcept {}
        PerspectiveTransform3D(void* ptr, take_ownership_from_abi_t) noexcept : Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D(ptr, take_ownership_from_abi) {}
        PerspectiveTransform3D();
        [[nodiscard]] static auto DepthProperty();
        [[nodiscard]] static auto OffsetXProperty();
        [[nodiscard]] static auto OffsetYProperty();
    };
    struct __declspec(empty_bases) Transform3D : Windows::UI::Xaml::Media::Media3D::ITransform3D,
        impl::base<Transform3D, Windows::UI::Xaml::DependencyObject>,
        impl::require<Transform3D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
    {
        Transform3D(std::nullptr_t) noexcept {}
        Transform3D(void* ptr, take_ownership_from_abi_t) noexcept : Windows::UI::Xaml::Media::Media3D::ITransform3D(ptr, take_ownership_from_abi) {}
    };
}
#endif
