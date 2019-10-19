// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_ADJACENT_AURA_HPP
#define ROSETTASTONE_ADJACENT_AURA_HPP

#include <Rosetta/Auras/Aura.hpp>

namespace RosettaStone
{
class FieldZone;
class Minion;

//!
//! \brief AdjacentAura class.
//!
//! This class is an aura for adjacent type. Note that some auras only affect
//! adjacent minions, e.g. Dire Wolf Alpha and Flametongue Totem.
//!
class AdjacentAura : public IAura
{
 public:
    //! Constructs adjacent aura with given \p effects.
    //! \param enchantmentID The enchantment card ID.
    AdjacentAura(std::string&& enchantmentID);

    //! Create new Aura instance to the owner's game.
    //! \param owner An owner of enrage effect.
    //! \param cloning The flag to indicate that it is cloned.
    void Activate(Entity* owner,
                  [[maybe_unused]] bool cloning = false) override;

    //! Updates this effect to apply the effect to recently modified entities.
    void Update() override;

    //! Removes this effect from the game to stop affecting entities.
    void Remove() override;

    //! Clones aura effect to \p clone.
    //! \param clone The entity to clone aura effect.
    void Clone(Entity* clone) override;

    //! Sets the flag whether the field zone is changed.
    //! \param isFieldChanged The flag whether the field zone is changed.
    void SetIsFieldChanged(bool isFieldChanged);

 private:
    //! Constructs enrage effect with given \p prototype, \p owner
    //! and \p cloning.
    //! \param prototype An enrage effect for prototype.
    //! \param owner An owner of adaptive effect.
    //! \param cloning The flag to indicate that it is cloned.
    AdjacentAura(AdjacentAura& prototype, Minion& owner, bool cloning);

    //! Applies aura's effect(s) to target minion.
    //! \param minion The minion to apply aura's effect(s).
    void Apply(Minion* minion);

    //! Disapplies aura's effect(s) to target minion.
    //! \param minion The minion to disapply aura's effect(s).
    void Disapply(Minion* minion);

    Minion* m_owner = nullptr;
    Card* m_enchantmentCard = nullptr;
    std::vector<IEffect*> m_effects;

    FieldZone* m_fieldZone = nullptr;
    Minion* m_left = nullptr;
    Minion* m_right = nullptr;

    bool m_isFieldChanged = false;
    bool m_toBeRemoved = false;
};
}  // namespace RosettaStone

#endif  // ROSETTASTONE_ADJACENT_AURA_HPP
