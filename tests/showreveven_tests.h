#ifndef SHOWREVEVEN_TESTS_H
#define SHOWREVEVEN_TESTS_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <fstream>

extern "C" {
#include "text.h"
#include "common.h"
}

std::string GetText(std::string filename) {
	std::ifstream t(filename);
	std::stringstream buffer;
	buffer << t.rdbuf();
	std::string target = buffer.str();
	return target;
}

TEST(showreveven, Default) {	
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input1.txt");
	show_rev_even(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output1.txt");
	
	ASSERT_EQ(output, target);
}

TEST(showreveven, NullFile) {
	testing::internal::CaptureStderr();
	
	show_rev_even(NULL);
	
	std::string output = testing::internal::GetCapturedStderr();
	
	ASSERT_NE(output, "");
}

TEST(mnlb, Default) {
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input2.txt");
	set_cursor(txt, 0, 0);
	mnlb(txt);
	show(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output2.txt");
	
	ASSERT_EQ(output, target);
}

TEST(mnlb, NullFile) {
	testing::internal::CaptureStderr();

	mnlb(NULL);
	
	std::string output = testing::internal::GetCapturedStderr();
	ASSERT_NE(output, "");
}

TEST(mnlb, EmptyFile) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	mnlb(txt);
	
	std::string output = testing::internal::GetCapturedStderr();
	ASSERT_NE(output, "");
}

TEST(mnlb, OneLine) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	load(txt, "tests/input/input3.txt");
	set_cursor(txt, 0, 0);
	mnlb(txt);
	
	std::string output = testing::internal::GetCapturedStderr();
	
	ASSERT_NE(output, "");
}

TEST(p, Default) {
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input4.txt");
	p(txt, 1, "Huh");
	show(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output4.txt");
	
	ASSERT_EQ(output, target);
}

#endif