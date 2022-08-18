#include <iostream>
#include <array>
#include <algorithm>

#include "imgui.h"
#include "implot.h"

#include "render.hpp"

void render_window1()
{
    ImGui::SetNextWindowPos(ImVec2{ 0.0, 0.0 }, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2{ 300.0, 150.0 }, ImGuiCond_FirstUseEver);
    if (ImGui::Begin("window1", nullptr, ImGuiWindowFlags_NoScrollbar))
    {
        if (ImGui::BeginTable("table1", 3, ImGuiTableFlags_Borders))
        {
            for (int row = 0; row < 4; row++)
            {
                ImGui::TableNextRow();

                for (int column = 0; column < 3; column++)
                {
                    ImGui::TableSetColumnIndex(column);
                    ImGui::Text("Cell value");
                }
            }

            ImGui::EndTable();
        }

        ImGui::End();
    }
}

void render_window2()
{
    ImGui::SetNextWindowPos(ImVec2{ 500.0, 500.0 }, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2{ 300.0, 150.0 }, ImGuiCond_FirstUseEver);
    if (ImGui::Begin("window2", nullptr, ImGuiWindowFlags_NoScrollbar))
    {
        if (ImGui::BeginTable("table2", 3, ImGuiTableFlags_Borders))
        {
            for (int row = 0; row < 4; row++)
            {
                ImGui::TableNextRow();

                for (int column = 0; column < 3; column++)
                {
                    ImGui::TableSetColumnIndex(column);
                    ImGui::Text("Cell value");
                }
            }

            ImGui::EndTable();
        }

        ImGui::End();
    }
}

void render_window3()
{
    ImGui::SetNextWindowPos(ImVec2{ 900.0, 300.0 }, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2{ 300.0, 150.0 }, ImGuiCond_FirstUseEver);
    if (ImGui::Begin("window3", nullptr, ImGuiWindowFlags_NoScrollbar))
    {
        if (ImGui::Button("myButton", ImVec2{ 100.0F, 50.0F }))
        {
            std::cout << "Clicked\n";
        }

        ImGui::End();
    }
}

void render_window4()
{
    constexpr auto size1 = 1001U;
    constexpr auto size2 = 11U;

    auto xs1 = std::array<float, size1>{};
    auto ys1 = std::array<float, size1>{};
    for (std::size_t i = 0U; i < size1; ++i)
    {
        xs1[i] = i * 0.001f;
        ys1[i] = 0.5f + 0.5f * sinf(50 * (xs1[i] + static_cast<float>(ImGui::GetTime() / 10)));
    }

    auto xs2 = std::array<float, size2>{};
    auto ys2 = std::array<float, size2>{};
    for (std::size_t i = 0U; i < size2; ++i)
    {
        xs2[i] = i * 0.1f;
        ys2[i] = xs2[i] * xs2[i];
    }

    ImGui::SetNextWindowPos(ImVec2{ 0.0, 150.0 }, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2{ 600.0, 350.0 }, ImGuiCond_FirstUseEver);
    if (ImGui::Begin("window4", nullptr, ImGuiWindowFlags_NoScrollbar))
    {
        ImPlot::CreateContext();

        if (ImPlot::BeginPlot("Line Plot"))
        {
            ImPlot::SetupAxes("x", "f(x)");
            ImPlot::PlotLine("sin(x)", xs1.data(), ys1.data(), static_cast<int>(size1));
            ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
            ImPlot::PlotLine("x^2", xs2.data(), ys2.data(), static_cast<int>(size2));
            ImPlot::EndPlot();
        }

        ImGui::End();
    }
}

void render()
{
    render_window1();
    render_window2();
    render_window3();
    render_window4();
}
