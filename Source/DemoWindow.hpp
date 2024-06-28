#pragma once
#include <Framework.hpp>
#include <Generated/Config.hpp>

namespace UImGuiDemo 
{
    class UIMGUI_PUBLIC_API DemoWindow : public UImGui::WindowComponent
    {
    public:
        DemoWindow();
        virtual void begin() override;
        virtual void tick(float deltaTime) override;
        virtual void end() override;
        virtual ~DemoWindow() override;
    private:

    };
}
