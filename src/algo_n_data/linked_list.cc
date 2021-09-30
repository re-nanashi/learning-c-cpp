#include <iostream>

class Part
{
  public:
    Part() : itsPartNumber(1)
    {
    }
    Part(int PartNumber) : itsPartNumber(PartNumber)
    {
    }
    virtual ~Part(){};
    int GetPartNumber() const
    {
        return itsPartNumber;
    }
    virtual void Display() const = 0;

  private:
    int itsPartNumber;
};

void Part::Display() const
{
    std::cout << "\nPart Number: " << itsPartNumber << std::endl;
}

class CarPart : public Part
{
  public:
    CarPart() : itsModelYear(94)
    {
    }
    CarPart(int year, int partNumber);
    virtual void Display() const
    {
        Part::Display();
        std::cout << "Model Year: ";
        std::cout << itsModelYear << std::endl;
    }

  private:
    int itsModelYear;
};

CarPart::CarPart(int year, int partNumber) : Part(partNumber), itsModelYear(year)
{
}

class AirPlanePart : public Part
{
  public:
    AirPlanePart() : itsEngineNumber(1)
    {
    }
    AirPlanePart(int EngineNumber, int PartNumber);
    virtual void Display() const
    {
        Part::Display();
        std::cout << "Engine No.: ";
        std::cout << itsEngineNumber << std::endl;
    }

  private:
    int itsEngineNumber;
};

AirPlanePart::AirPlanePart(int EngineNumber, int partNumber) : Part(partNumber), itsEngineNumber(EngineNumber)
{
}

class PartNode
{
  public:
    PartNode(Part *);
    ~PartNode();
    void SetNext(PartNode *node)
    {
        itsNext = node;
    }
    PartNode *GetNext() const;
    Part *GetPart() const;

  private:
    Part *itsPart;
    PartNode *itsNext;
};

PartNode::PartNode(Part *pPart) : itsPart(pPart), itsNext(0)
{
}

PartNode::~PartNode()
{
    delete itsPart;
    itsPart = 0;
    delete itsNext;
    itsNext = 0;
}

PartNode *PartNode::GetNext() const
{
    return itsNext;
}

Part *PartNode::GetPart() const
{
    if (itsPart)
        return itsPart;
    else
        return NULL;
}
