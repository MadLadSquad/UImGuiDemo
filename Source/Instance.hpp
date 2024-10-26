#pragma once
#include <Framework.hpp>
#include <Generated/Config.hpp>
#include <DemoWindow.hpp>

namespace UImGuiDemo
{
    class UIMGUI_PUBLIC_API Instance final : public UImGui::Instance
    {
    public:
        Instance() noexcept;
        virtual void begin() noexcept override;
        virtual void tick(float deltaTime) noexcept override;
        virtual void end() noexcept override;
        virtual ~Instance() noexcept override = default;

        virtual void onEventConfigureStyle(ImGuiStyle& style, ImGuiIO& io) noexcept override;
    private:
        DemoWindow demoWindow{};
    };
}
