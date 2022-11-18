#include "string_type.h"

String stringCreate(char *string)
{
    String result;
    size_t length, i;
    char *content;

    result.content = NULL;
    content = NULL;

    length = strlen(string);
    content = (char *)malloc(length + 1);

    if (content == NULL)
        return result;

    for (i = 0; i < length; i++)
    {
        content[i] = string[i];
    }

    content[length] = '\0';

    result.content = content;

    return result;
}

int stringDestroy(String *string)
{
    char *aux;

    aux = string->content;

    if (aux == NULL)
        return 0;

    free(aux);
    return 1;
}

size_t stringLength(String string)
{
    size_t i;

    i = 0;

    while (string.content[i] != '\0')
    {
        i++;
    }

    return i;
}

String stringConcat(String source, String destination)
{
    size_t lengthSource, lengthDestination, lengthResult, i;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    lengthSource = stringLength(source);
    lengthDestination = stringLength(destination);
    lengthResult = lengthSource + lengthDestination;

    resultContent = (char *)malloc(lengthResult + 1);

    if (resultContent == NULL)
        return;

    for (i = 0; i < lengthResult; i++)
    {
        if (i < lengthDestination)
            resultContent[i] = destination.content[i];

        else
            resultContent[i] = source.content[i - lengthDestination];
    }

    resultContent[lengthResult] = '\0';

    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

String stringReplace(String original, String toReplace, String replaceBy)
{
    size_t lengthOriginal, lengthToReplace, lengthReplaceBy, lengthResult, i, j, d;
    String resultString;
    char *resultContent;
    int counter, foundWord;
    int firstLetterIndex, lastLetterIndex;

    resultString.content = NULL;
    resultContent = NULL;

    counter = 0;
    foundWord = 0;

    firstLetterIndex = -1;
    lastLetterIndex = -1;

    lengthToReplace = stringLength(toReplace);
    lengthOriginal = stringLength(original);
    lengthReplaceBy = stringLength(replaceBy);

    lengthResult = 0;

    j = 0;

    // Verify where, at 'original', we have the string 'toReplace'
    for (i = 0; i < lengthOriginal - lengthToReplace + 1; i++)
    {
        if (original.content[i] != toReplace.content[j])
        {
            counter = 0;
            j = 0;
            continue;
        }

        else if (original.content[i] == toReplace.content[j])
        {
            counter += 1;
            j += 1;
        }

        if (counter == lengthToReplace)
        {
            lastLetterIndex = i;
            foundWord = 1;
            break;
        }
    }

    j = 0;

    if (foundWord)
    {
        firstLetterIndex = lastLetterIndex - lengthToReplace + 1;

        if (lengthReplaceBy == lengthToReplace)
        {
            lengthResult = lengthOriginal;

            resultContent = (char *)malloc(lengthResult + 1);

            for (i = 0; i < lengthResult; i++)
            {
                if (i >= firstLetterIndex && i <= lastLetterIndex)
                {
                    resultContent[i] = replaceBy.content[j];
                    j += 1;
                }

                else
                    resultContent[i] = original.content[i];
            }
        }

        if (lengthReplaceBy > lengthToReplace)
        {
            d = lengthReplaceBy - lengthToReplace;
            lengthResult = lengthOriginal + d;

            resultContent = (char *)malloc(lengthResult + 1);

            for (i = 0; i < lengthResult; i++)
            {
                if (i >= firstLetterIndex && i <= lastLetterIndex + d)
                {
                    resultContent[i] = replaceBy.content[j];
                    j += 1;
                }

                else
                {
                    if (i > lastLetterIndex)
                        resultContent[i] = original.content[i - d];

                    else if (i < firstLetterIndex)
                        resultContent[i] = original.content[i];
                }
            }
        }

        if (lengthReplaceBy < lengthToReplace)
        {
            d = lengthToReplace - lengthReplaceBy;
            lengthResult = lengthOriginal - d;

            resultContent = (char *)malloc(lengthResult + 1);

            for (i = 0; i < lengthResult; i++)
            {
                if (i >= firstLetterIndex && i <= lastLetterIndex - d)
                {
                    resultContent[i] = replaceBy.content[j];
                    j += 1;
                }

                else
                {
                    if (i < firstLetterIndex)
                        resultContent[i] = original.content[i];

                    else
                        resultContent[i] = original.content[i + d];
                }
            }
        }

        resultContent[lengthResult] = '\0';
        resultString = stringCreate(resultContent);

        free(resultContent);
    }

    return resultString;
}

String stringToLower(String original)
{
    size_t lengthOriginal, i;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    lengthOriginal = stringLength(original);

    resultContent = (char *)malloc(lengthOriginal + 1);

    if (resultContent == NULL)
        return;

    for (i = 0; i < lengthOriginal; i++)
    {
        resultContent[i] = tolower(original.content[i]);
    }

    resultContent[lengthOriginal] = '\0';
    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

String stringToUpper(String original)
{
    size_t lengthOriginal, i;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    lengthOriginal = stringLength(original);

    resultContent = (char *)malloc(lengthOriginal + 1);

    if (resultContent == NULL)
        return;

    for (i = 0; i < lengthOriginal; i++)
    {
        resultContent[i] = toupper(original.content[i]);
    }

    resultContent[lengthOriginal] = '\0';
    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

String stringTrim(String original)
{
    size_t lengthOriginal, lengthResult, initIndex, endIndex, i;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    initIndex = 0;
    endIndex = lengthOriginal - 1;

    lengthResult = 0;

    lengthOriginal = stringLength(original);

    // Finding initIndex
    for (i = 0; i < lengthOriginal; i++)
    {
        if (original.content[i] != ' ')
        {
            initIndex = i;
            break;
        }
    }

    // Finding endIndex
    for (i = lengthOriginal - 1; i >= 0; i--)
    {
        if (original.content[i] != ' ')
        {
            endIndex = i;
            break;
        }
    }

    lengthResult = endIndex - initIndex + 1;

    resultContent = (char *)malloc(lengthResult + 1);

    if (resultContent == NULL)
        return;

    for (i = 0; i < lengthResult; i++)
    {
        resultContent[i] = original.content[i + initIndex];
    }

    resultContent[lengthResult] = '\0';
    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

int stringContains(String original, String substring)
{
    size_t lengthOriginal, lengthSubstring, i, j;
    unsigned int counter;

    lengthOriginal = stringLength(original);
    lengthSubstring = stringLength(substring);

    j = 0;
    counter = 0;

    for (i = 0; i < lengthOriginal; i++)
    {
        if (original.content[i] == substring.content[0])
        {
            counter += 1;

            for (j = 1; j < lengthSubstring; j++)
            {
                if (original.content[i + j] == substring.content[j])
                    counter += 1;

                else
                {
                    counter = 0;
                    break;
                }
            }
        }

        if (counter == lengthSubstring)
            return 1;
    }

    return 0;
}

int stringStartsWith(String original, String substring)
{
    size_t lengthOriginal, lengthSubstring, i;

    lengthOriginal = stringLength(original);
    lengthSubstring = stringLength(substring);

    if (lengthSubstring > lengthOriginal)
        return 0;

    for (i = 0; i < lengthSubstring; i++)
    {
        if (original.content[i] != substring.content[i])
            return 0;
    }

    return 1;
}

int stringEndsWith(String original, String substring)
{
    size_t lengthOriginal, lengthSubstring;
    int i, j;

    lengthOriginal = stringLength(original);
    lengthSubstring = stringLength(substring);

    if (lengthSubstring > lengthOriginal)
        return 0;

    j = lengthOriginal - 1;

    for (i = lengthSubstring - 1; i >= 0; i--)
    {
        if (original.content[j] != substring.content[i])
            return 0;

        j--;
    }

    return 1;
}

int stringAreEqual(String string1, String string2)
{
    size_t lengthString1, lengthString2, i;

    lengthString1 = stringLength(string1);
    lengthString2 = stringLength(string2);

    if (lengthString1 != lengthString2)
        return 0;

    for (i = 0; i < lengthString1; i++)
    {
        if (string1.content[i] != string2.content[i])
            return 0;
    }

    return 1;
}

String stringCopy(String string)
{
    return stringCreate(string.content);
}
