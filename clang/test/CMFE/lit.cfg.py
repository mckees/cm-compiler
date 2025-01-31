#=========================== begin_copyright_notice ============================
#
# Copyright (C) 2014-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
#============================ end_copyright_notice =============================

# -*- Python -*-

# Configuration file for the 'lit' test runner.

import os

import lit.formats
import lit.util

from lit.llvm import llvm_config
from lit.llvm.subst import ToolSubst
from lit.llvm.subst import FindTool

# name: The name of this test suite.
config.name = 'CMFE'

# suffixes: A list of file extensions to treat as test files.
config.suffixes = ['.cpp']

config.test_source_root = os.path.dirname(__file__)

# testFormat: The test format to use to interpret tests.
config.test_format = lit.formats.ShTest(not llvm_config.use_lit_shell)

# Discover the 'cmc' command to use.
tools = [ToolSubst('%cmc', command=FindTool('cmc')), 'not']
tool_dirs = [config.clang_tools_dir, config.llvm_tools_dir]
llvm_config.add_tool_substitutions(tools, tool_dirs)

llvm_config.use_default_substitutions()

config.substitutions.append(
    ('%dump-ast-for', '-Xclang -ast-dump -Xclang -ast-dump-filter -Xclang'))
