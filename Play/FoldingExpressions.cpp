
//////////////////////////  Folding Expressions ///////////////////////////////////
template<typename... Args>
auto sum(Args... args) {
	// Unary folding.
	return (... + args);
}

void FoldingExpressionsPlay()
{

	sum(1.0, 2.0f, 3); // == 6.0
}
