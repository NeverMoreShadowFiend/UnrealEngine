// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

class GRAPHEDITOR_API SGraphNodeK2Copy : public SGraphNodeK2Base
{
public:
	SLATE_BEGIN_ARGS(SGraphNodeK2Copy) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UK2Node* InNode);

	//~ Begin SGraphNode Interface
	virtual void UpdateGraphNode() override;
	virtual TSharedRef<SWidget> CreateNodeContentArea() override;
	virtual void AddPin(const TSharedRef<SGraphPin>& PinToAdd) override;
	virtual const FSlateBrush* GetShadowBrush(bool bSelected) const override;
	virtual TSharedPtr<SGraphPin> CreatePinWidget(UEdGraphPin* Pin) const override;
	//~ End SGraphNode Interface
};
