### 解释器模式总结

#### 概述
解释器模式（Interpreter Pattern）是一种行为型设计模式，它用于定义一个语言的文法，并解释语言中的句子。解释器模式通常用于设计一种简单的语言或表达式求值器，例如数学表达式求值器、正则表达式解析器等。

### 抽象代码实现

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

// 抽象表达式类 (AbstractExpression)
class AbstractExpression {
public:
    virtual ~AbstractExpression() = default;
    virtual int Interpret(const std::unordered_map<std::string, int>& context) const = 0;
};

// 终结符表达式类 (TerminalExpression)
class TerminalExpression : public AbstractExpression {
public:
    TerminalExpression(const std::string& variable) : variable_(variable) {}

    int Interpret(const std::unordered_map<std::string, int>& context) const override {
        return context.at(variable_);
    }

private:
    std::string variable_;
};

// 非终结符表达式类 (NonterminalExpression)
class NonterminalExpression : public AbstractExpression {
public:
    NonterminalExpression(std::shared_ptr<AbstractExpression> left, std::shared_ptr<AbstractExpression> right)
        : left_(left), right_(right) {}

protected:
    std::shared_ptr<AbstractExpression> left_;
    std::shared_ptr<AbstractExpression> right_;
};

// 加法表达式类 (AddExpression)
class AddExpression : public NonterminalExpression {
public:
    using NonterminalExpression::NonterminalExpression;

    int Interpret(const std::unordered_map<std::string, int>& context) const override {
        return left_->Interpret(context) + right_->Interpret(context);
    }
};

// 减法表达式类 (SubtractExpression)
class SubtractExpression : public NonterminalExpression {
public:
    using NonterminalExpression::NonterminalExpression;

    int Interpret(const std::unordered_map<std::string, int>& context) const override {
        return left_->Interpret(context) - right_->Interpret(context);
    }
};

// 客户端代码
int main() {
    // 构建语法树
    std::shared_ptr<AbstractExpression> expression = std::make_shared<AddExpression>(
        std::make_shared<TerminalExpression>("x"),
        std::make_shared<SubtractExpression>(
            std::make_shared<TerminalExpression>("y"),
            std::make_shared<TerminalExpression>("z")
        )
    );

    // 上下文，包含变量的值
    std::unordered_map<std::string, int> context = { {"x", 5}, {"y", 10}, {"z", 3} };

    // 解释表达式
    int result = expression->Interpret(context);
    std::cout << "Result: " << result << std::endl; // 输出: 12

    return 0;
}
```

### 代码解释

1. **抽象表达式类（AbstractExpression）**：
    - 定义了解释操作的接口 `Interpret`。所有具体的表达式类都要实现这个接口。

2. **终结符表达式类（TerminalExpression）**：
    - 表示一个变量，它在解释操作中返回上下文中对应的值。

3. **非终结符表达式类（NonterminalExpression）**：
    - 包含左表达式和右表达式，定义了所有非终结符表达式的基础。

4. **加法表达式类（AddExpression）**和**减法表达式类（SubtractExpression）**：
    - 分别实现了加法和减法操作，解释操作时分别对左表达式和右表达式进行求值，并返回结果。

5. **客户端代码**：
    - 构建一个表示表达式 `x + (y - z)` 的语法树。
    - 创建包含变量值的上下文。
    - 调用解释操作计算表达式的值并输出结果。

### 总结
解释器模式通过定义一个抽象语法树，并实现解释操作，使得可以根据上下文对表达式进行求值。其主要优点包括易于扩展新的语法规则、代码清晰易懂以及符合开闭原则。然而，解释器模式也可能导致类的数量急剧增加，从而增加系统的复杂性。在实际应用中，解释器模式适用于设计简单的语言或表达式求值器，如数学表达式求值器、正则表达式解析器等。理解和应用解释器模式，可以帮助开发者构建灵活、可扩展和可维护的系统。