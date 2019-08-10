// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

// It is based on peter1591's hearthstone-ai repository.
// References: https://github.com/peter1591/hearthstone-ai

#include <MCTS/Policies/Simulation/ISimulationPolicy.hpp>

namespace RosettaTorch::MCTS
{
ChoiceGetter::ChoiceGetter(int choices) : m_choices(choices)
{
    // Do nothing
}

size_t ChoiceGetter::Size() const
{
    return static_cast<size_t>(m_choices);
}

int ChoiceGetter::Get(size_t idx) const
{
    return static_cast<int>(idx);
}

void ChoiceGetter::ForEachChoice(const std::function<bool(int)>& functor) const
{
    for (int i = 0; i < m_choices; ++i)
    {
        if (!functor(i))
        {
            return;
        }
    }
}
}  // namespace RosettaTorch::MCTS