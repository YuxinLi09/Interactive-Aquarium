/**
* \file Item.h
*
* \author Yuxin Li
*
* Base class for any item in our aquarium.
*/


#pragma once

#ifndef CITEM_H
#define CITEM_H

#include "XmlNode.h"
#include <string>
#include <memory>

using namespace xmlnode;
class CAquarium;

/**
 * Base class for any item in our aquarium.
 */
class CItem
{
public:
    /// Default constructor (disabled)
    CItem() = delete;

    /// Copy constructor (disabled)
    CItem(const CItem&) = delete;

    virtual ~CItem();

    /** The X location of the item
     * \returns X location in pixels */
    double GetX() const { return mX; }

    /** The Y location of the item
    * \returns Y location in pixels */
    double GetY() const { return mY; }

    /** Set the item location
     * \param x X location
     * \param y Y location */
    void SetLocation(double x, double y) { mX = x; mY = y; }

    virtual void Draw(Gdiplus::Graphics* graphics);

    virtual bool HitTest(int x, int y);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        CItem::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

    virtual void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /// Handle updates for animation
    /// \param elapsed The time since the last update
    virtual void Update(double elapsed) {}

    /// Get the aquarium this item is in
    /// \returns Aquarium pointer
    CAquarium* GetAquarium() { return mAquarium; }

    /// Get the width of the item
    /// \returns item width
    double CItem::GetItemWidth() { return mItemImage->GetWidth(); }

    /// Get the item of the aquarium
    /// \returns item width
    double CItem::GetItemHeight() { return mItemImage->GetHeight(); }

    /// Set the mirror status
    /// \param m New mirror flag
    void SetMirror(bool m) { mMirror = m; }

protected:
    /** Constructor
    * \param aquarium The aquarium this item is a member of
    * \param filename The filename of this item's image
    */
    CItem(CAquarium* aquarium, const std::wstring& filename);

private:
    /// The aquarium this item is contained in
    CAquarium* mAquarium;

    bool mMirror = false;   ///< True mirrors the item image

    // Item location in the aquarium
    double   mX = 0;     ///< X location for the center of the item
    double   mY = 0;     ///< Y location for the center of the item

    /// The image of this fish
    std::unique_ptr<Gdiplus::Bitmap> mItemImage;

};

#endif