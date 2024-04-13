#pragma once

// Define a type trait to check if the matrix is square
template <typename MatrixType>
struct IsSquareMatrix {
    static constexpr bool value = MatrixType::get_nrows() == MatrixType::get_ncols();
};

// Define lambda templates for custom transformations
auto customTransform = [](const auto& element) {
    // Implement custom transformation logic here
    return element;  // Example: identity transformation
};

#pragma once

// Define lambda templates for custom transformations
namespace MatrixOperations {
    auto customTransform = [](const auto& element) {
        // Implement custom transformation logic here
        return element;  // Example: identity transformation
    };
}

