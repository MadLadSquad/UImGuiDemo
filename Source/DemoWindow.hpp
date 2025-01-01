#pragma once
#include <Framework.hpp>
#include <Generated/Config.hpp>

namespace UImGuiDemo 
{
    class UIMGUI_PUBLIC_API DemoWindow final : public UImGui::WindowComponent
    {
    public:
        DemoWindow() noexcept;
        virtual void begin() noexcept override;
        virtual void tick(float deltaTime) noexcept override;
        virtual void end() noexcept override;
        virtual ~DemoWindow() noexcept override = default;
    private:
        UImGui::Texture tex;
    };
}
