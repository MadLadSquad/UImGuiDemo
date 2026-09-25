#pragma once
#include <Framework.hpp>
#include <Generated/Config.hpp>

namespace UImGuiDemo
{
    class UIMGUI_PUBLIC_API AboutWindow final : public UImGui::WindowComponent
    {
    public:
        AboutWindow() noexcept = default;
        virtual void begin() noexcept override;
        virtual void tick(float deltaTime) noexcept override;
        virtual void end() noexcept override;
        virtual ~AboutWindow() noexcept override = default;
    private:
        struct LicenseEntry
        {
            const char* name;
            const char* author;
            const char* license;
            const char* file;
            UImGui::FString text{};
        };

        struct LicenseGroup
        {
            const char* name;
            UImGui::TVector<LicenseEntry> entries;
        };

        static void renderGroup(LicenseGroup& group) noexcept;

        UImGui::Texture logo{};
        // The window is a one-shot popup: once closed, it is never shown again
        bool bOpen = true;
        bool bFirstFrame = true;

        UImGui::TVector<LicenseGroup> groups{};
    };
}
