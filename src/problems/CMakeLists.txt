cmake_minimum_required(VERSION 3.18)

project(Problems
  VERSION 0.0.1
  HOMEPAGE_URL ${CODING_INTERVIEWS_HOMEPAGE_URL}
  LANGUAGES CXX
)

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

###
### Variables
###
# set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
# set(HEADER_FILES ${CODINGINTERVIEWS_INCLUDE_DIR}/foo.hpp)

###
### Define library target
###
add_library(${PROJECT_NAME}_Toolbelt                                         ${CMAKE_CURRENT_SOURCE_DIR}/toolbelt/toolbelt.cpp)
add_executable(${PROJECT_NAME}_Toolbelt_Test                                 ${CMAKE_CURRENT_SOURCE_DIR}/toolbelt/toolbelt_test.cpp)
add_executable(${PROJECT_NAME}_Binary_Search_Tree                            ${CMAKE_CURRENT_SOURCE_DIR}/binary_search_tree.cpp)
add_executable(${PROJECT_NAME}_Concatenated_Words                            ${CMAKE_CURRENT_SOURCE_DIR}/concatenated_words/concatenated_words.cpp)
add_executable(${PROJECT_NAME}_Contiguous_Subarrays                          ${CMAKE_CURRENT_SOURCE_DIR}/contiguous_subarrays/contiguous_subarrays.cpp)
add_executable(${PROJECT_NAME}_Graph_BFS_DFS                                 ${CMAKE_CURRENT_SOURCE_DIR}/graph_bfs_dfs.cpp)
add_executable(${PROJECT_NAME}_Knapsack                                      ${CMAKE_CURRENT_SOURCE_DIR}/knapsack_and_subset_sums/knapsack.cpp)
add_executable(${PROJECT_NAME}_Linked_List_Mergesort_and_Reverse             ${CMAKE_CURRENT_SOURCE_DIR}/linked_list_mergesort_and_reverse.cpp)
add_executable(${PROJECT_NAME}_Longest_Substring_Without_Repeated_Characters ${CMAKE_CURRENT_SOURCE_DIR}/longest_substring_without_repeated_characters/longest_substring_without_repeated_characters.cpp)
add_executable(${PROJECT_NAME}_Pair_Sums                                     ${CMAKE_CURRENT_SOURCE_DIR}/pair_sums/pair_sums.cpp)
add_executable(${PROJECT_NAME}_Rotational_Cipher                             ${CMAKE_CURRENT_SOURCE_DIR}/rotational_cipher/rotational_cipher.cpp)
add_executable(${PROJECT_NAME}_Search_Revenue_Milestones                     ${CMAKE_CURRENT_SOURCE_DIR}/search_revenue_milestones/search_revenue_milestones.cpp)
add_executable(${PROJECT_NAME}_Subset_Sums                                   ${CMAKE_CURRENT_SOURCE_DIR}/knapsack_and_subset_sums/subset_sums.cpp)
add_executable(${PROJECT_NAME}_Trie_Word_Dictionary                          ${CMAKE_CURRENT_SOURCE_DIR}/trie_word_dictionary/trie_word_dictionary.cpp)
add_executable(${PROJECT_NAME}_First_Unique_Character                        ${CMAKE_CURRENT_SOURCE_DIR}/first_unique_character/first_unique_character.cpp)
add_executable(${PROJECT_NAME}_Max_Points_From_Adding_Card_Scores            ${CMAKE_CURRENT_SOURCE_DIR}/max_points_from_adding_card_scores/max_points_from_adding_card_scores.cpp)
add_executable(${PROJECT_NAME}_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown ${CMAKE_CURRENT_SOURCE_DIR}/best_time_to_buy_and_sell_stock_with_cooldown/best_time_to_buy_and_sell_stock_with_cooldown.cpp)
add_executable(${PROJECT_NAME}_Walking_Robot_Simulation_II                   ${CMAKE_CURRENT_SOURCE_DIR}/walking_robot_simulation_ii/walking_robot_simulation_ii.cpp)

target_include_directories(${PROJECT_NAME}_Toolbelt      PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CODINGINTERVIEWS_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME}_Toolbelt_Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CODINGINTERVIEWS_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME}_Toolbelt_Test PUBLIC ${PROJECT_NAME}_Toolbelt)

target_compile_options(${PROJECT_NAME}_Toolbelt                                      PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Toolbelt_Test                                 PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Binary_Search_Tree                            PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Concatenated_Words                            PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Contiguous_Subarrays                          PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Graph_BFS_DFS                                 PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Knapsack                                      PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Linked_List_Mergesort_and_Reverse             PRIVATE -Werror -Wall -Wextra -pedantic -g)
target_compile_options(${PROJECT_NAME}_Longest_Substring_Without_Repeated_Characters PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Pair_Sums                                     PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Rotational_Cipher                             PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Search_Revenue_Milestones                     PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Subset_Sums                                   PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Trie_Word_Dictionary                          PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_First_Unique_Character                        PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Max_Points_From_Adding_Card_Scores            PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}_Walking_Robot_Simulation_II                   PRIVATE -Werror -Wall -Wextra -pedantic)
