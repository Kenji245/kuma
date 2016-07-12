/* Copyright (c) 2016, Fengping Bao <jamol@live.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __H2Connection_H__
#define __H2Connection_H__

#include "kmdefs.h"
#include "FrameParser.h"
#include "HPacker.h"

#include <map>

KUMA_NS_BEGIN

class H2Connection : public FrameCallback
{
public:
	H2Connection();
	~H2Connection();
    
public:
    void onFrame(H2Frame *frame);
    void onFrameError(const FrameHeader &hdr, H2Error err);

private:
    FrameParser parser_;
    HPacker hpEncoder_;
    HPacker hpDecoder_;
};

KUMA_NS_END

#endif