#include <iostream>
#include <memory>

#include "Context.hpp"
#include "Expression.hpp"
#include "NumberExpression.hpp"
#include "AddExpression.hpp"
#include "SubtractExpression.hpp"

int main()
{

    Context context;

    std::unique_ptr<Expression> expr2 = std::make_unique<NumberExpression>(2);
    std::unique_ptr<Expression> expr3 = std::make_unique<NumberExpression>(3);
    std::unique_ptr<Expression> addExpr = std::make_unique<AddExpression>(std::move(expr2), std::move(expr3));

    std::unique_ptr<Expression> expr1 = std::make_unique<NumberExpression>(1);
    std::unique_ptr<Expression> finalExpr = std::make_unique<SubtractExpression>(std::move(addExpr), std::move(expr1));

    std::cout << "Expression: " << finalExpr->ToString() << std::endl;
    int result = finalExpr->Interpret(context);
    std::cout << "Result: " << result << std::endl;

    std::unique_ptr<Expression> expr10 = std::make_unique<NumberExpression>(10);
    std::unique_ptr<Expression> expr5 = std::make_unique<NumberExpression>(5);
    std::unique_ptr<Expression> anotherAddExpr = std::make_unique<AddExpression>(std::move(expr10), std::move(expr5));
    std::cout << "Expression: " << anotherAddExpr->ToString() << std::endl;
    int anotherResult = anotherAddExpr->Interpret(context);
    std::cout << "Result: " << anotherResult << std::endl;
    return 0;
}