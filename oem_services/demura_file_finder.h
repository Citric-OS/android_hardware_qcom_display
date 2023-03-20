/*
 *Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *    * Neither the name of The Linux Foundation nor the names of its
 *      contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 *THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 *WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 *ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 *BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 *OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 *IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *Changes from Qualcomm Innovation Center are provided under the following license:
 *Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
 *SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#ifndef __DEMURA_FILE_FINDER_H__
#define __DEMURA_FILE_FINDER_H__

#include <aidl/vendor/qti/hardware/display/demura/BnDemuraFileFinder.h>
#include <log/log.h>
#include <utils/sys.h>
#include <file_finder_interface.h>

namespace aidl {
namespace vendor {
namespace qti {
namespace hardware {
namespace display {
namespace demura {
namespace implementation {
using sdm::FileFinderInterface;
using ::aidl::vendor::qti::hardware::display::demura::IDemuraFileFinder;
using DemuraFilePaths = IDemuraFileFinder::DemuraFilePaths;

#define OEM_FILE_FINDER_LIB_NAME "libfilefinder.so"
#define GET_FILE_FINDER_INTF_NAME "GetFileFinderIntf"
#define DESTROY_FILE_FINDER_INTF_NAME "DestroyFileFinderIntf"
typedef FileFinderInterface *(*GetFileFinderIntf)();
typedef void *(*DestroyFileFinderIntf)();

class DemuraFileFinder : public BnDemuraFileFinder {
 public:
  virtual ~DemuraFileFinder();
  static int Init();
  static FileFinderInterface *file_intf_;
  static DestroyFileFinderIntf destroy_ff_intf_;

  // IDemuraFileFinder
  ::ndk::ScopedAStatus getDemuraFilePaths(int64_t in_panel_id,
                                          DemuraFilePaths* out_file_paths);

 private:
};

}  // namespace implementation
}  // namespace demura
}  // namespace display
}  // namespace hardware
}  // namespace qti
}  // namespace vendor
}  // namespace aidl

#endif  // __DEMURA_FILE_FINDER_H__
