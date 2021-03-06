<? namespace Isak\Work;

class TransformationArr
{
    private $smmItemsNewArray = 0;
    private $arInfo = array();
    private $arItems = array();
    private const MAX_VALUE_NEW_ARRAY = 2;
    private const MIN_VALUE_NEW_ARRAY = -14;
    private const MAX_LENGTH_ARRAY_ITEMS = 24;
    private const MAX_VALUE = 32;
    private const MIN_VALUE = -32;
    private const SPLIT_ARRAY_ITEMS = "<br>";

    private function getStringFromArray(string $title, array $data): string
    {
        return $title .self::SPLIT_ARRAY_ITEMS .implode(", ", $data) .self::SPLIT_ARRAY_ITEMS;
    }

    private function setInfo(string $title, array $data): void
    {
        array_push($this->arInfo, $this->getStringFromArray($title, $data));
    }

    public function getInfoToString(): string
    {
        return implode(self::SPLIT_ARRAY_ITEMS, $this->arInfo);
    }

    private function getRandArrValues(): array
    {
        $arItems = array();
        for($index = 0; $index < self::MAX_LENGTH_ARRAY_ITEMS; $index++)
        {
            array_push($arItems, rand(self::MIN_VALUE, self::MAX_VALUE));
        }

        $this->setInfo("Первоначальный массив: ", $arItems);
        return $arItems;
    }

    private function valideValueArr(int $number): bool
    {
        return ($number >= self::MIN_VALUE_NEW_ARRAY && $number <= self::MAX_VALUE_NEW_ARRAY);
    }

    private function transformationArray(): array
    {
        $newArray = array();
        foreach ($this->arItems as $key => $number)
        {
            if(is_numeric($number))
            {
                $this->arItems[$key] -= 6;
                if($this->valideValueArr($number))
                {
                    $this->smmItemsNewArray += $this->arItems[$key];
                    array_push($newArray, $this->arItems[$key]);
                }
            }
        }
        $this->setInfo("Преобразованный массив: ", $this->arItems);
        $this->setInfo("Новый массив: ", $newArray);
        $this->setInfo("Сумма значений нового массива: ", array($this->smmItemsNewArray));
        return $newArray;
    }

    public function main(): void
    {
        $this->arItems = $this->getRandArrValues();
        $newArItems = $this->transformationArray();
    }
}
?>