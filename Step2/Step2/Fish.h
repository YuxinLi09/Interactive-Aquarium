/**
 * \file CatFish.h
 *
 * \author Yuxin Li
 *
 * Class the implements a fish
 */

#pragma once

#ifndef CFISH_H
#define CFISH_H

#include "Item.h"
#include <memory>
#include <string>

/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class CFish : public CItem
{

public:
    /// Default constructor (disabled)
    CFish() = delete;

    /// Copy constructor (disabled)
    CFish(const CFish&) = delete;

    void CFish::Update(double);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

protected:

    CFish::CFish(CAquarium* aquarium, const std::wstring& filename);

    /// Maximum speed in the X direction in
    /// in pixels per second *****used to be a const double
    double MaxSpeedX;

    /// Maximum speed in the X direction in
    /// in pixels per second *****used to be a const double
    double MaxSpeedY;

    /// Minimum speed in the X direction in
    /// in pixels per second *****used to be a const double
    double MinSpeedX;

    /// Minimum speed in the X direction in
    /// in pixels per second *****used to be a const double
    double MinSpeedY;

private:
    /// Fish speed in the X direction
    double mSpeedX;

    /// Fish speed in the Y direction
    double mSpeedY;


};

#endif