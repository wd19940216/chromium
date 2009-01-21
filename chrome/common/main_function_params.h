// Copyright (c) 2009 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Wrapper to the parameter list for the "main" entry points (browser, renderer,
// plugin) to shield the call sites from the differences between platforms
// (e.g., POSIX doesn't need to pass any sandbox information).

#ifndef CHROME_COMMON_MAIN_FUNCTINON_PARAMS_H_
#define CHROME_COMMON_MAIN_FUNCTINON_PARAMS_H_

#include "base/command_line.h"
#include "chrome/common/sandbox_init_wrapper.h"

struct MainFunctionParams {
  MainFunctionParams(const CommandLine& cl, const SandboxInitWrapper& sb)
      : command_line_(cl), sandbox_info_(sb) { }
  const CommandLine& command_line_;
  const SandboxInitWrapper& sandbox_info_;
};

#endif  // CHROME_COMMON_MAIN_FUNCTINON_PARAMS_H_
