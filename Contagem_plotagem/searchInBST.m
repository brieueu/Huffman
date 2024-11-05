function [found, comparisons] = searchInBST(node, value)
    comparisons = 0;
    found = false;
    while ~isempty(node)
        comparisons = comparisons + 1;
        if value == node.value
            found = true;
            break;
        elseif value < node.value
            node = node.left;
        else
            node = node.right;
        end
    end
end
