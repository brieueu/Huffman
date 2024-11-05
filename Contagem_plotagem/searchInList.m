function [found, comparisons] = searchInList(list, value)
    comparisons = 0;
    found = false;
    for i = 1:length(list)
        comparisons = comparisons + 1;
        if list(i) == value
            found = true;
            break;
        end
    end
end
