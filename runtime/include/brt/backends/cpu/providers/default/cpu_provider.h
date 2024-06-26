//===- cpu_provider.h -----------------------------------------*--- C++ -*-===//
//
// Copyright 2022 ByteDance Ltd. and/or its affiliates. All rights reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//===----------------------------------------------------------------------===//

#pragma once

#include "brt/backends/common.h"
#include "brt/core/common/status.h"
#include "brt/core/framework/execution_provider.h"

namespace brt {
class Session;

struct CPUExecutionProviderOptions : ProviderOptions {
  int brt_omp_num_threads;
};

class CPUExecutionProvider : public ExecutionProvider {
public:
  explicit CPUExecutionProvider(const CPUExecutionProviderOptions &options,
                                const std::string &name = ProviderType::BRT);

  const CPUExecutionProviderOptions &GetProviderOptions() const;

protected:
  CPUExecutionProviderOptions options_;
};

common::Status NaiveCPUExecutionProviderFactory(Session *session);

// TODO add more option later
common::Status
NaiveCPUExecutionProviderFactory(Session *session,
                                 const CPUExecutionProviderOptions &options);

} // namespace brt
