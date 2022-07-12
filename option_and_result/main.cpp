#include <iostream>

enum class OptionType { Some, None };

template <typename T>
struct Option {
  OptionType type;
  union {
    struct {
      T value;
    };          // Some
    struct {};  // None
  };
};

enum class ResultType { Ok, Error };

template <typename T, typename E>
struct Result {
  ResultType type;
  union {
    struct {
      T value;
    };  // Ok
    struct {
      E error;
    };  // Error
  };
};

enum class ErrorCode { DIVISION_BY_ZERO };

template <typename T>
Option<T> option_div(T numerator, T denominator) {
  if (denominator == 0) {
    return Option<T>{OptionType::None};
  }
  return Option<T>{OptionType::Some, .value = (numerator / denominator)};
}

template <typename T>
Result<T, ErrorCode> result_div(T numerator, T denominator) {
  if (denominator == 0) {
    return Result<T, ErrorCode>{ResultType::Error,
                                .error = ErrorCode::DIVISION_BY_ZERO};
  }
  return Result<T, ErrorCode>{ResultType::Ok,
                              .value = (numerator / denominator)};
}

// Helpers.

template <typename T>
void print(Option<T> option) {
  switch (option.type) {
    case OptionType::Some:
      std::cout << "Some: " << option.value << std::endl;
      break;
    case OptionType::None:
      std::cout << "None" << std::endl;
      break;
    default:
      break;
  }
}

template <typename T, typename E>
void print(Result<T, E> result) {
  switch (result.type) {
    case ResultType::Ok:
      std::cout << "Ok: " << result.value << std::endl;
      break;
    case ResultType::Error:
      switch (result.error) {
        case ErrorCode::DIVISION_BY_ZERO:
          std::cout << "Error: Division by Zero" << std::endl;
          break;
        default:
          std::cout << "Error" << std::endl;
          break;
      }
      break;
    default:
      break;
  }
}

int main() {
  std::cout << "Option type examples" << std::endl;
  print(option_div(4, 2));
  print(option_div(4, 1));
  print(option_div(4, 0));

  std::cout << "Result type examples" << std::endl;
  print(result_div(4, 2));
  print(result_div(4, 1));
  print(result_div(4, 0));
}
