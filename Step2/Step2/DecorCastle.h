/**
 * \file DecorCastle.h
 *
 * \author Yuxin Li
 *
 * Class the implements an Castle
 */

#pragma once

#ifndef CCASTLE_H
#define CCASTLE_H

#include "Item.h"
#include <memory>
#include <string>

/**
 * Implements an Item
 */
class CDecorCastle : public CItem
{
public:
    CDecorCastle(CAquarium* aquarium);

    /// Default constructor (disabled)
    CDecorCastle() = delete;

    /// Copy constructor (disabled)
    CDecorCastle(const CDecorCastle&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

#endif

