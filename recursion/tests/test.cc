#include "gtest/gtest.h"

#include <algorithm>
#include <memory>
#include <numeric>
#include <random>
#include <sstream>
#include <vector>

#include "solutions.h"

TEST(module2, ShouldDrawSpiral) {
    {
        std::ostringstream os;
        Window window(4, os);
        window.drawSpiral();
        EXPECT_EQ(os.str(), std::string("* * * * * \n"
                                        "        * \n"
                                        "*       * \n"
                                        "*       * \n"
                                        "* * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(5, os);
        window.drawSpiral();
        EXPECT_EQ(os.str(), std::string("* * * * * * \n"
                                        "          * \n"
                                        "* * * *   * \n"
                                        "*   * *   * \n"
                                        "*         * \n"
                                        "* * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(6, os);
        window.drawSpiral();
        EXPECT_EQ(os.str(), std::string("* * * * * * * \n"
                                        "            * \n"
                                        "* * * * *   * \n"
                                        "*       *   * \n"
                                        "*   * * *   * \n"
                                        "*           * \n"
                                        "* * * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(7, os);
        window.drawSpiral();
        EXPECT_EQ(os.str(), std::string("* * * * * * * * \n"
                                        "              * \n"
                                        "* * * * * *   * \n"
                                        "*         *   * \n"
                                        "*   *     *   * \n"
                                        "*   * * * *   * \n"
                                        "*             * \n"
                                        "* * * * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(13, os);
        window.drawSpiral();
        EXPECT_EQ(os.str(), std::string(
                                "* * * * * * * * * * * * * * \n"
                                "                          * \n"
                                "* * * * * * * * * * * *   * \n"
                                "*                     *   * \n"
                                "*   * * * * * * * *   *   * \n"
                                "*   *             *   *   * \n"
                                "*   *   * * * *   *   *   * \n"
                                "*   *   *   * *   *   *   * \n"
                                "*   *   *         *   *   * \n"
                                "*   *   * * * * * *   *   * \n"
                                "*   *                 *   * \n"
                                "*   * * * * * * * * * *   * \n"
                                "*                         * \n"
                                "* * * * * * * * * * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(15, os);
        window.drawSpiral();
        EXPECT_EQ(os.str(), std::string("* * * * * * * * * * * * * * * * \n"
                                        "                              * \n"
                                        "* * * * * * * * * * * * * *   * \n"
                                        "*                         *   * \n"
                                        "*   * * * * * * * * * *   *   * \n"
                                        "*   *                 *   *   * \n"
                                        "*   *   * * * * * *   *   *   * \n"
                                        "*   *   *         *   *   *   * \n"
                                        "*   *   *   *     *   *   *   * \n"
                                        "*   *   *   * * * *   *   *   * \n"
                                        "*   *   *             *   *   * \n"
                                        "*   *   * * * * * * * *   *   * \n"
                                        "*   *                     *   * \n"
                                        "*   * * * * * * * * * * * *   * \n"
                                        "*                             * \n"
                                        "* * * * * * * * * * * * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(17, os);
        window.drawSpiral();
        EXPECT_EQ(os.str(), std::string("* * * * * * * * * * * * * * * * * * \n"
                                        "                                  * \n"
                                        "* * * * * * * * * * * * * * * *   * \n"
                                        "*                             *   * \n"
                                        "*   * * * * * * * * * * * *   *   * \n"
                                        "*   *                     *   *   * \n"
                                        "*   *   * * * * * * * *   *   *   * \n"
                                        "*   *   *             *   *   *   * \n"
                                        "*   *   *   * * * *   *   *   *   * \n"
                                        "*   *   *   *   * *   *   *   *   * \n"
                                        "*   *   *   *         *   *   *   * \n"
                                        "*   *   *   * * * * * *   *   *   * \n"
                                        "*   *   *                 *   *   * \n"
                                        "*   *   * * * * * * * * * *   *   * \n"
                                        "*   *                         *   * \n"
                                        "*   * * * * * * * * * * * * * *   * \n"
                                        "*                                 * \n"
                                        "* * * * * * * * * * * * * * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(20, os);
        window.drawSpiral();
        EXPECT_EQ(os.str(), std::string("* * * * * * * * * * * * * * * * * * * * * \n"
                                        "                                        * \n"
                                        "* * * * * * * * * * * * * * * * * * *   * \n"
                                        "*                                   *   * \n"
                                        "*   * * * * * * * * * * * * * * *   *   * \n"
                                        "*   *                           *   *   * \n"
                                        "*   *   * * * * * * * * * * *   *   *   * \n"
                                        "*   *   *                   *   *   *   * \n"
                                        "*   *   *   * * * * * * *   *   *   *   * \n"
                                        "*   *   *   *           *   *   *   *   * \n"
                                        "*   *   *   *   *       *   *   *   *   * \n"
                                        "*   *   *   *   *       *   *   *   *   * \n"
                                        "*   *   *   *   * * * * *   *   *   *   * \n"
                                        "*   *   *   *               *   *   *   * \n"
                                        "*   *   *   * * * * * * * * *   *   *   * \n"
                                        "*   *   *                       *   *   * \n"
                                        "*   *   * * * * * * * * * * * * *   *   * \n"
                                        "*   *                               *   * \n"
                                        "*   * * * * * * * * * * * * * * * * *   * \n"
                                        "*                                       * \n"
                                        "* * * * * * * * * * * * * * * * * * * * * \n"));
    }
}

TEST(module2, ShouldDrawPattern1) {
    {
        std::ostringstream os;
        Window window(6, os);
        window.drawPattern();
        EXPECT_EQ(os.str(), std::string(
                                "    * *       \n"
                                "  *     *     \n"
                                "*   * *   *   \n"
                                "*   * *   *   \n"
                                "  *     *     \n"
                                "    * *       \n"
                                "              \n"));
    }
    {
        std::ostringstream os;
        Window window(8, os);
        window.drawPattern();
        EXPECT_EQ(os.str(), std::string(
                                "      * *         \n"
                                "    *     *       \n"
                                "  *   * *   *     \n"
                                "*   *     *   *   \n"
                                "*   *     *   *   \n"
                                "  *   * *   *     \n"
                                "    *     *       \n"
                                "      * *         \n"
                                "                  \n"));
    }
    {
        std::ostringstream os;
        Window window(12, os);
        window.drawPattern();
        EXPECT_EQ(os.str(), std::string(
                                "          * *             \n"
                                "        *     *           \n"
                                "      *   * *   *         \n"
                                "    *   *     *   *       \n"
                                "  *   *   * *   *   *     \n"
                                "*   *   *     *   *   *   \n"
                                "*   *   *     *   *   *   \n"
                                "  *   *   * *   *   *     \n"
                                "    *   *     *   *       \n"
                                "      *   * *   *         \n"
                                "        *     *           \n"
                                "          * *             \n"
                                "                          \n"));
    }
    {
        std::ostringstream os;
        Window window(16, os);
        window.drawPattern();
        EXPECT_EQ(os.str(), std::string(
                                "              * *                 \n"
                                "            *     *               \n"
                                "          *   * *   *             \n"
                                "        *   *     *   *           \n"
                                "      *   *   * *   *   *         \n"
                                "    *   *   *     *   *   *       \n"
                                "  *   *   *   * *   *   *   *     \n"
                                "*   *   *   *     *   *   *   *   \n"
                                "*   *   *   *     *   *   *   *   \n"
                                "  *   *   *   * *   *   *   *     \n"
                                "    *   *   *     *   *   *       \n"
                                "      *   *   * *   *   *         \n"
                                "        *   *     *   *           \n"
                                "          *   * *   *             \n"
                                "            *     *               \n"
                                "              * *                 \n"
                                "                                  \n"));
    }
    {
        std::ostringstream os;
        Window window(20, os);
        window.drawPattern();
        EXPECT_EQ(os.str(), std::string(
                                "                  * *                     \n"
                                "                *     *                   \n"
                                "              *   * *   *                 \n"
                                "            *   *     *   *               \n"
                                "          *   *   * *   *   *             \n"
                                "        *   *   *     *   *   *           \n"
                                "      *   *   *   * *   *   *   *         \n"
                                "    *   *   *   *     *   *   *   *       \n"
                                "  *   *   *   *   * *   *   *   *   *     \n"
                                "*   *   *   *   *     *   *   *   *   *   \n"
                                "*   *   *   *   *     *   *   *   *   *   \n"
                                "  *   *   *   *   * *   *   *   *   *     \n"
                                "    *   *   *   *     *   *   *   *       \n"
                                "      *   *   *   * *   *   *   *         \n"
                                "        *   *   *     *   *   *           \n"
                                "          *   *   * *   *   *             \n"
                                "            *   *     *   *               \n"
                                "              *   * *   *                 \n"
                                "                *     *                   \n"
                                "                  * *                     \n"
                                "                                          \n"));
    }
}

TEST(module2, ShouldDrawPattern2) {
    {
        std::ostringstream os;
        Window window(4, os);
        window.drawPattern2();
        EXPECT_EQ(os.str(), std::string(
                                "* * * * * \n"
                                "*     * * \n"
                                "*     * * \n"
                                "* * *   * \n"
                                "* * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(6, os);
        window.drawPattern2();
        EXPECT_EQ(os.str(), std::string(
                                "* * * * * * * \n"
                                "* *     *   * \n"
                                "*         * * \n"
                                "*         * * \n"
                                "* *     *   * \n"
                                "*   * *     * \n"
                                "* * * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(8, os);
        window.drawPattern2();
        EXPECT_EQ(os.str(), std::string(
                                "* * * * * * * * * \n"
                                "*   *     *     * \n"
                                "* *         *   * \n"
                                "*             * * \n"
                                "*             * * \n"
                                "* *         *   * \n"
                                "*   *     *     * \n"
                                "*     * *       * \n"
                                "* * * * * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(10, os);
        window.drawPattern2();
        EXPECT_EQ(os.str(), std::string(
                                "* * * * * * * * * * * \n"
                                "*     *     *       * \n"
                                "*   *         *     * \n"
                                "* *             *   * \n"
                                "*       * * *     * * \n"
                                "*       * * *     * * \n"
                                "* *     * * *   *   * \n"
                                "*   *         *     * \n"
                                "*     *     *       * \n"
                                "*       * *         * \n"
                                "* * * * * * * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(12, os);
        window.drawPattern2();
        EXPECT_EQ(os.str(), std::string(
                                "* * * * * * * * * * * * * \n"
                                "*       *     *         * \n"
                                "*     *         *       * \n"
                                "*   *             *     * \n"
                                "* *     * * * * *   *   * \n"
                                "*       *     * *     * * \n"
                                "*       *     * *     * * \n"
                                "* *     * * *   *   *   * \n"
                                "*   *   * * * * * *     * \n"
                                "*     *         *       * \n"
                                "*       *     *         * \n"
                                "*         * *           * \n"
                                "* * * * * * * * * * * * * \n"));
    }
    {
        std::ostringstream os;
        Window window(16, os);
        window.drawPattern2();
        EXPECT_EQ(os.str(), std::string(
                                "* * * * * * * * * * * * * * * * * \n"
                                "*           *     *             * \n"
                                "*         *         *           * \n"
                                "*       *             *         * \n"
                                "*     * * * * * * * * * *       * \n"
                                "*   *   *   *     *     * *     * \n"
                                "* *     * *         *   *   *   * \n"
                                "*       *             * *     * * \n"
                                "*       *             * *     * * \n"
                                "* *     * *         *   *   *   * \n"
                                "*   *   *   *     *     * *     * \n"
                                "*     * *     * *       *       * \n"
                                "*       * * * * * * * * *       * \n"
                                "*         *         *           * \n"
                                "*           *     *             * \n"
                                "*             * *               * \n"
                                "* * * * * * * * * * * * * * * * * \n"));
    }
}

TEST(module2, ShouldCalculateRPN) {
    std::vector<std::string> vec{"3", "1", "2", "+", "*", "2", "/"};
    ASSERT_DOUBLE_EQ(rpn(vec.cbegin(), vec.cend()), 4.5);

    vec = {"8", "7", "+", "3", "/", "2", "*", "4", "+", "2", "^"};
    ASSERT_DOUBLE_EQ(rpn(vec.cbegin(), vec.cend()), 196);

    vec = {"2", "7", "+", "3", "/", "14", "3", "-", "4", "*", "+", "2", "/"};
    ASSERT_DOUBLE_EQ(rpn(vec.cbegin(), vec.cend()), 23.5);
}

TEST(module2, ShouldSolveHanoi) {
    auto vec = hanoi(1);
    EXPECT_EQ(vec, std::vector<std::string>({"Move: 1 | from: A to: C\n"}));

    vec = hanoi(2);
    EXPECT_EQ(vec, std::vector<std::string>({"Move: 1 | from: A to: B\n", "Move: 2 | from: A to: C\n", "Move: 1 | from: B to: C\n"}));

    vec = hanoi(3);
    EXPECT_EQ(vec, std::vector<std::string>({"Move: 1 | from: A to: C\n", "Move: 2 | from: A to: B\n", "Move: 1 | from: C to: B\n", "Move: 3 | from: A to: C\n", "Move: 1 | from: B to: A\n", "Move: 2 | from: B to: C\n", "Move: 1 | from: A to: C\n"}));

    vec = hanoi(4);
    EXPECT_EQ(vec, std::vector<std::string>({"Move: 1 | from: A to: B\n", "Move: 2 | from: A to: C\n", "Move: 1 | from: B to: C\n", "Move: 3 | from: A to: B\n", "Move: 1 | from: C to: A\n", "Move: 2 | from: C to: B\n", "Move: 1 | from: A to: B\n", "Move: 4 | from: A to: C\n", "Move: 1 | from: B to: C\n", "Move: 2 | from: B to: A\n", "Move: 1 | from: C to: A\n", "Move: 3 | from: B to: C\n", "Move: 1 | from: A to: B\n", "Move: 2 | from: A to: C\n", "Move: 1 | from: B to: C\n"}));

    vec = hanoi(5);
    EXPECT_EQ(vec, std::vector<std::string>({"Move: 1 | from: A to: C\n", "Move: 2 | from: A to: B\n", "Move: 1 | from: C to: B\n", "Move: 3 | from: A to: C\n", "Move: 1 | from: B to: A\n", "Move: 2 | from: B to: C\n", "Move: 1 | from: A to: C\n", "Move: 4 | from: A to: B\n", "Move: 1 | from: C to: B\n", "Move: 2 | from: C to: A\n", "Move: 1 | from: B to: A\n", "Move: 3 | from: C to: B\n", "Move: 1 | from: A to: C\n", "Move: 2 | from: A to: B\n", "Move: 1 | from: C to: B\n", "Move: 5 | from: A to: C\n", "Move: 1 | from: B to: A\n", "Move: 2 | from: B to: C\n", "Move: 1 | from: A to: C\n", "Move: 3 | from: B to: A\n", "Move: 1 | from: C to: B\n", "Move: 2 | from: C to: A\n", "Move: 1 | from: B to: A\n", "Move: 4 | from: B to: C\n", "Move: 1 | from: A to: C\n", "Move: 2 | from: A to: B\n", "Move: 1 | from: C to: B\n", "Move: 3 | from: A to: C\n", "Move: 1 | from: B to: A\n", "Move: 2 | from: B to: C\n", "Move: 1 | from: A to: C\n"}));
}
