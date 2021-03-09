/**
 * \file AngelFish.h
 *
 * \author Yuxin Li
 *
 * Class the implements an Angelfish
 */

#pragma once

#ifndef CANGELFISH_H
#define CANGELFISH_H

#include "Fish.h"
#include "XmlNode.h"
#include <memory>
#include <string>

 /**
  * Implements an angelfish
  */
class CAngelFish : public CFish
{
public:
    CAngelFish(CAquarium* aquarium);

    /// Default constructor (disabled)
    CAngelFish() = delete;

    /// Copy constructor (disabled)
    CAngelFish(const CAngelFish&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};

#endif