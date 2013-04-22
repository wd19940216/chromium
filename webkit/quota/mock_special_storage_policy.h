// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WEBKIT_QUOTA_MOCK_SPECIAL_STORAGE_POLICY_H_
#define WEBKIT_QUOTA_MOCK_SPECIAL_STORAGE_POLICY_H_

#include <set>
#include <string>

#include "googleurl/src/gurl.h"
#include "webkit/quota/special_storage_policy.h"

namespace quota {

class MockSpecialStoragePolicy : public quota::SpecialStoragePolicy {
 public:
  MockSpecialStoragePolicy();

  virtual bool IsStorageProtected(const GURL& origin) OVERRIDE;
  virtual bool IsStorageUnlimited(const GURL& origin) OVERRIDE;
  virtual bool IsStorageSessionOnly(const GURL& origin) OVERRIDE;
  virtual bool CanQueryDiskSize(const GURL& origin) OVERRIDE;
  virtual bool IsFileHandler(const std::string& extension_id) OVERRIDE;
  virtual bool HasSessionOnlyOrigins() OVERRIDE;

  void AddProtected(const GURL& origin) {
    protected_.insert(origin);
  }

  void AddUnlimited(const GURL& origin) {
    unlimited_.insert(origin);
  }

  void AddSessionOnly(const GURL& origin) {
    session_only_.insert(origin);
  }

  void GrantQueryDiskSize(const GURL& origin) {
    can_query_disk_size_.insert(origin);
  }

  void AddFileHandler(const std::string& id) {
    file_handlers_.insert(id);
  }

  void SetAllUnlimited(bool all_unlimited) {
    all_unlimited_ = all_unlimited;
  }

  void Reset() {
    protected_.clear();
    unlimited_.clear();
    session_only_.clear();
    can_query_disk_size_.clear();
    file_handlers_.clear();
    all_unlimited_ = false;
  }

  void NotifyCleared() {
    SpecialStoragePolicy::NotifyCleared();
  }

 protected:
  virtual ~MockSpecialStoragePolicy();

 private:
  std::set<GURL> protected_;
  std::set<GURL> unlimited_;
  std::set<GURL> session_only_;
  std::set<GURL> can_query_disk_size_;
  std::set<std::string> file_handlers_;

  bool all_unlimited_;
};
}  // namespace quota

#endif  // WEBKIT_QUOTA_MOCK_SPECIAL_STORAGE_POLICY_H_
