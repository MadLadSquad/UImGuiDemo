#include "AboutWindow.hpp"

#include "../../UntitledDEPolkitAgent/Framework/Core/Interfaces/LayoutsInterface.hpp"

// Horizontally centres the next widget of the given width inside the current window
static void centreNext(const float width) noexcept
{
    const float offset = (ImGui::GetContentRegionAvail().x - width) * 0.5f;
    if (offset > 0.0f)
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + offset);
}

static void centredText(const char* text) noexcept
{
    centreNext(ImGui::CalcTextSize(text).x);
    ImGui::TextUnformatted(text);
}

void UImGuiDemo::AboutWindow::begin() noexcept
{
    beginAutohandle();

    logo.init(UIMGUI_CONTENT_DIR"uimgui-logo.png");
    logo.load();

    groups =
    {
        {
            .name = "Core",
            .entries =
            {
                {
                    .name = "dear imgui",
                    .author = "Omar Cornut",
                    .license = "MIT",
                    .file = "Licenses/imgui.txt"
                },
                {
                    .name = "GLFW",
                    .author = "Marcus Geelnard, Camilla Loewy",
                    .license = "Zlib",
                    .file = "Licenses/glfw.txt"
                },
                {
                    .name = "FreeType",
                    .author = "The FreeType Project",
                    .license = "FTL or GPL-2.0",
                    .file = "Licenses/freetype.txt"
                },
                {
                    .name = "rapidyaml",
                    .author = "Joao Paulo Magalhaes",
                    .license = "MIT",
                    .file = "Licenses/rapidyaml.txt"
                },
                {
                    .name = "utfcpp",
                    .author = "Nemanja Trifunovic",
                    .license = "BSL-1.0",
                    .file = "Licenses/utfcpp.txt"
                },
                {
                    .name = "UntitledLog",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/UntitledLog.txt"
                },
                {
                    .name = "UntitledRuntimeLibraryLoader",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/urll.txt"
                },
                {
                    .name = "parallel-hashmap",
                    .author = "Gregory Popovitch",
                    .license = "Apache-2.0",
                    .file = "Licenses/parallel-hashmap.txt"
                },
                {
                    .name = "stb_image, stb_image_write",
                    .author = "Sean Barrett",
                    .license = "MIT or Unlicense",
                    .file = "Licenses/stb.txt"
                },
                {
                    .name = "Dear Bindings (cimgui)",
                    .author = "Ben Carter",
                    .license = "MIT",
                    .file = "Licenses/dear_bindings.txt"
                },
                {
                    .name = "glad",
                    .author = "David Herberth",
                    .license = "(WTFPL or CC0-1.0) and Apache-2.0",
                    .file =  "Licenses/glad.txt"
                },
                {
                    .name = "Vulkan-Headers",
                    .author = "The Khronos Group Inc.",
                    .license = "Apache-2.0 or MIT",
                    .file = "Licenses/vulkan-headers.txt"
                },
                {
                    .name = "Vulkan Loader",
                    .author = "The Khronos Group Inc., LunarG Inc.",
                    .license = "Apache-2.0",
                    .file = "Licenses/vulkan-loader.txt"
                },
                {
                    .name = "Dawn (emdawnwebgpu)",
                    .author = "The Dawn & Tint Authors",
                    .license = "BSD-3-Clause",
                    .file = "Licenses/dawn.txt"
                },
            }
        },
        {
            .name = "Modules",
            .entries =
            {
                {
                    .name = "ImPlot",
                    .author = "Evan Pezent",
                    .license = "MIT",
                    .file = "Licenses/implot.txt"
                },

                {
                    .name = "imgui-knobs",
                    .author = "Simon Altschuler",
                    .license = "MIT",
                    .file = "Licenses/imgui-knobs.txt"
                },
                {
                    .name = "imspinner",
                    .author = "Dalerank",
                    .license = "MIT",
                    .file = "Licenses/imspinner.txt"
                },
                {
                    .name = "imgui_toggle",
                    .author = "nitz (chris marc dailey)",
                    .license = "0BSD",
                    .file = "Licenses/imgui_toggle.txt"
                },
                {
                    .name = "UntitledImGuiTextUtils",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/UntitledImGuiTextUtils.txt"
                },
                {
                    .name = "UntitledI18N",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/UntitledI18N.txt"
                },
                {
                    .name = "UntitledImGuiTheme",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/UntitledImGuiTheme.txt"
                },
                {
                    .name = "UntitledOpen",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/UntitledOpen.txt"
                },
                {
                    .name = "UntitledExec",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/UntitledExec.txt"
                },
                {
                    .name = "UntitledDBusUtils",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/UntitledDBusUtils.txt"
                },
                {
                    .name = "UntitledXDGBasedir",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/UntitledXDGBasedir.txt"
                },
                {
                    .name = "UntitledCLIParser",
                    .author = "Heapforge Ltd.",
                    .license = "MIT",
                    .file = "Licenses/UntitledCLIParser.txt"
                },
            }
        },
        {
            .name = "Assets & fonts",
            .entries =
            {
                {
                    .name = "Ubuntu Font Family",
                    .author = "Canonical Ltd., Dalton Maag",
                    .license = "Ubuntu Font Licence 1.0",
                    .file = "UFL.txt"
                },
                {
                    .name = "JetBrains Mono",
                    .author = "The JetBrains Mono Project Authors",
                    .license = "OFL-1.1",
                    .file = "OFL.txt"
                },
            }
        },
    };

    for (auto& group : groups)
    {
        for (auto& entry : group.entries)
        {
            entry.text = UImGui::Utility::loadFileToString(UImGui::FString(UIMGUI_CONTENT_DIR) + entry.file);
            if (entry.text.empty())
            {
                Logger::log("Couldn't load the license text for ", ULOG_LOG_TYPE_WARNING, entry.name, " from ", entry.file);
                entry.text = "License text unavailable";
            }
        }
    }
}

void UImGuiDemo::AboutWindow::renderGroup(LicenseGroup& group) noexcept
{
    ImGui::SeparatorText(group.name);
    for (auto& entry : group.entries)
    {
        if (ImGui::CollapsingHeader(entry.name))
        {
            ImGui::PushID(entry.file);
            ImGui::TextDisabled("%s - %s", entry.author, entry.license);

            // Read-only, so the buffer is never written to. Gives us scrolling and text selection for free
            ImGui::InputTextMultiline(
                "##license",
                entry.text.data(),
                entry.text.size() + 1,
                {
                    -FLT_MIN,
                    ImGui::GetTextLineHeight() * 14.0f
                },
                ImGuiInputTextFlags_ReadOnly
            );

            ImGui::PopID();
        }
    }
}

void UImGuiDemo::AboutWindow::tick(const float deltaTime) noexcept
{
    tickAutohandle(deltaTime);
    if (!bOpen)
        return;

    ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Appearing, { 0.5f, 0.5f });
    ImGui::SetNextWindowSize({ 360.0f, 360.0f }, ImGuiCond_Appearing);
    if (bFirstFrame)
    {
        ImGui::SetNextWindowFocus();
        bFirstFrame = false;
    }

    if (ImGui::Begin("About UntitledImGuiFramework", &bOpen, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings))
    {
        constexpr float logoSize = 128.0f;
        ImGui::Spacing();
        centreNext(logoSize);
        ImGui::Image(logo, { logoSize, logoSize });
        ImGui::Spacing();

        ImGui::PushFont(nullptr, ImGui::GetStyle().FontSizeBase * 1.5f);
        centredText("UntitledImGuiFramework");
        ImGui::PopFont();

        centredText("Version " UIMGUI_FRAMEWORK_VERSION);
        ImGui::Spacing();
        centredText("Copyright (c) 2022 - 2026 Heapforge Ltd.");
        centredText("Released under the MIT License");

        ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
        centredText("Logo designed and created by insekhta");
        ImGui::PopStyleColor();
        ImGui::Spacing();

        for (auto& group : groups)
            renderGroup(group);
    }
    ImGui::End();

    if (!bOpen)
        state = UIMGUI_COMPONENT_STATE_OFF;
}

void UImGuiDemo::AboutWindow::end() noexcept
{
    endAutohandle();

    logo.clear();
}
