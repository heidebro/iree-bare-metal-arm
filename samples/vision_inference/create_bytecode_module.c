// Copyright 2021 The IREE Authors
// Copyright 2022 Fraunhofer-Gesellschaft zur Förderung der angewandten
//                Forschung e.V.
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include <stdio.h>

#include "iree/vm/bytecode/module.h"
#include "mnist_c.h"

// A function to create the bytecode module.
iree_status_t create_module(iree_vm_instance_t* instance,
                            iree_vm_module_t** out_module) {
  const struct iree_file_toc_t* module_file_toc =
      iree_samples_static_library_mnist_create();
  iree_const_byte_span_t module_data =
      iree_make_const_byte_span(module_file_toc->data, module_file_toc->size);
  return iree_vm_bytecode_module_create(
      instance, module_data, iree_allocator_null(),
      iree_vm_instance_allocator(instance), out_module);
}

void print_success() { printf("mnist_static_library_run passed\n"); }
