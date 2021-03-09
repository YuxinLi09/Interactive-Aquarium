/**
 * \file Aquarium.h
 *
 * \author Yuxin Li
 *
 * Class that implements the aquarium our program draws in.
 *
 */

#pragma once

#ifndef CAQUARIUM_H
#define CAQUARIUM_H

#include "Item.h"
#include "XmlNode.h"
#include "FishBeta.h"
#include "AngelFish.h"
#include "CatFish.h"
#include "DecorCastle.h"
#include <algorithm>
#include <memory>
#include <vector>

/**
 * Implements an Aquarium
 */
class CAquarium
{
public:
    CAquarium();
    virtual ~CAquarium();

    void CAquarium::OnDraw(Gdiplus::Graphics*);
    void CAquarium::Add(std::shared_ptr<CItem>);
    void CAquarium::ToEnd(std::shared_ptr<CItem>);
    std::shared_ptr<CItem> CAquarium::HitTest(int x, int y);
    bool CAquarium::ToEndTest(std::shared_ptr<CItem>);
    void CAquarium::Save(const std::wstring&);
    void CAquarium::Load(const std::wstring&);
    void CAquarium::Clear();
    void CAquarium::Update(double);

    /// Get the width of the aquarium
    /// \returns Aquarium width
    int GetWidth() const { return mBackground->GetWidth(); }

    /// Get the height of the aquarium
    /// \returns Aquarium height
    int GetHeight() const { return mBackground->GetHeight(); }

private:
    std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image
    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<CItem> > mItems;
    void CAquarium::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>&);
};

#endif