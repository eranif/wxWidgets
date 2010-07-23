///////////////////////////////////////////////////////////////////////////////
// Name:        tests/asserthelper.cpp
// Purpose:     Helper functions for cppunit
// Author:      Steven Lamerton
// Created:     2010-07-23
// RCS-ID:      $Id$
// Copyright:   (c) 2009 Vadim Zeitlin <vadim@wxwidgets.org>
///////////////////////////////////////////////////////////////////////////////

#include <ostream>
#include <wx/colour.h>

namespace
{
    // by default colour components values are output incorrectly because they
    // are unsigned chars, define a small helper struct which formats them in
    // a more useful way
    struct ColourChannel
    {
        ColourChannel(unsigned char value) : m_value(value) { }

        unsigned char m_value;
    };

    std::ostream& operator<<(std::ostream& os, const ColourChannel& cc);

} // anonymous namespace

// this operator is needed to use CPPUNIT_ASSERT_EQUAL with wxColour objects
std::ostream& operator<<(std::ostream& os, const wxColour& c);
