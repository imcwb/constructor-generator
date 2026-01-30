#include <clang/AST/AST.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <clang/Rewrite/Core/Rewriter.h>
#include <iostream>
#include <string>

using namespace clang;
using namespace clang::tooling;

class ConstructorVisitor : public RecursiveASTVisitor<ConstructorVisitor> {
public:
    explicit ConstructorVisitor(ASTContext *Context) : Context(Context) {}

    bool VisitCXXRecordDecl(CXXRecordDecl *Declaration) {
        if (Declaration->isThisDeclarationADefinition() && !Declaration->isLocalClass()) {
            bool hasConstructor = false;
            for (const auto *Constructor : Declaration->ctors()) {
                if (Constructor->isDefaultConstructor()) {
                    hasConstructor = true;
                    break;
                }
            }
            if (!hasConstructor) {
                generateConstructor(Declaration);
            }
        }
        return true;
    }

private:
    ASTContext *Context;

    void generateConstructor(CXXRecordDecl *Declaration) {
        std::string constructorName = Declaration->getName().str();
        std::string initList;
        for (const auto *Field : Declaration->fields()) {
            initList += Field->getName().str() + "(0), ";  // Default initialization
        }
        initList = initList.substr(0, initList.size() - 2);  // Remove trailing comma

        std::cout << "Generating constructor: " << constructorName << "() : " << initList << " {}\n";
    }
};

class ConstructorAction : public ASTFrontendAction {
public:
    std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef InFile) override {
        return std::make_unique<ConstructorVisitor>(&CI.getASTContext());
    }
};

int main(int argc, const char **argv) {
    CommonOptionsParser OptionsParser(argc, argv, MyToolCategory);
    ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());
    return Tool.run(newFrontendAction<ConstructorAction>());
}